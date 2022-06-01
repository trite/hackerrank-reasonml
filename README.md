# Quick Getting Started:
`clone` the repo and `cd` into the local folder you save to (in this case `blarghle`):
```sh
$ git clone git@github.com:trite/hackerrank-reasonml.git blarghle
Cloning into 'blarghle'...
remote: Enumerating objects: 19, done.
remote: Counting objects: 100% (19/19), done.
remote: Compressing objects: 100% (16/16), done.
remote: Total 19 (delta 1), reused 19 (delta 1), pack-reused 0
Receiving objects: 100% (19/19), 283.99 KiB | 1.08 MiB/s, done.
Resolving deltas: 100% (1/1), done.
trite@DESKTOP-0ACBTNR:/mnt/c/git$ cd blarghle/
```

`npm install` next:
```sh
$ npm install
npm WARN deprecated source-map-url@0.4.1: See https://github.com/lydell/source-map-url#deprecated
npm WARN deprecated urix@0.1.0: Please see https://github.com/lydell/urix#deprecated
npm WARN deprecated resolve-url@0.2.1: https://github.com/lydell/resolve-url#deprecated
npm WARN deprecated source-map-resolve@0.5.3: See https://github.com/lydell/source-map-resolve#deprecated
npm WARN deprecated sane@4.1.0: some dependency vulnerabilities fixed, support for node < 10 dropped, and newer ECMAScript syntax/features added

added 580 packages, and audited 581 packages in 31s

34 packages are looking for funding
  run `npm fund` for details

found 0 vulnerabilities
```

You should now be able to `npm run build`:
```sh
$ npm run build

> hackerrank-reasonm@0.1.0 build
> bsb -make-world

Dependency on @glennsl/bs-jest
bsb: [5/5] src/jest.cmj
bsb: [7/7] install.stamp
Dependency Finished
bsb: [9/9] src/CompareTheTriplets.cmj
```

Last but not least executing an existing `src/*.re` file locally and feeding it input (2nd and 3rd lines below) via `node`:
```sh
$ node src/AVeryBigSum.bs.js
5 # <-- Manually entered --v
1000000001 1000000002 1000000003 1000000004 1000000005
5000000015 # <-- Output
```

# HackerRank-ReasonML
Project for making it easier to turn ReasonML into JavaScript targeted at HackerRank. Meaning you can:

## Step 0. Pre-requisites
You will need to run an `npm install` if you haven't yet for your local copy of this repo.

## Step 1. Write some ReasonML
Write your ReasonML code to solve the problem (this is still a bit hairy for me right now, cleaning things up eventually):
```reasonml
// https://www.hackerrank.com/challenges/a-very-big-sum/problem

Readline.readline(_ => {
  Readline.readline(line2 => {
    line2
    |> Js.String.split(" ")
    |> Js.Array.map(Int64.of_string)
    |> Js.Array.reduce(Int64.add, 0L)
    |> Int64.to_string
    |> Js.log;

    Readline.close();
  });
});
```

## Step 2. Compile and package to JS
This builds all Reason files in the `src` folder, despite the drawbacks which I am hastily ignoring ~~forever~~ for now. The file you specify will then be packaged into `dist/main.js` to be submitted to HackerRank.

It's a bit awkward having to specify a `.bs.js` file, especially if you haven't compiled the code since creating the corresponding `.re` file, need to think of better ways to handle this still.
```sh
$ npm run hackify ./src/AVeryBigSum.bs.js 

> hackerrank-reasonm@0.1.0 prehackify
> npm run build


> hackerrank-reasonm@0.1.0 build
> bsb -make-world

Dependency on @glennsl/bs-jest
Dependency Finished

> hackerrank-reasonm@0.1.0 hackify
> npx webpack build -t "node" --mode production --entry  "./src/AVeryBigSum.bs.js"

asset main.js 20.4 KiB [compared for emit] [minimized] (name: main)
modules by path ./node_modules/bs-platform/lib/js/*.js 52.5 KiB
  ./node_modules/bs-platform/lib/js/int64.js 1.34 KiB [built] [code generated]
  ./node_modules/bs-platform/lib/js/caml_int64.js 12.5 KiB [built] [code generated]
  ./node_modules/bs-platform/lib/js/caml_format.js 19.4 KiB [built] [code generated]
  ./node_modules/bs-platform/lib/js/caml_primitive.js 2.65 KiB [built] [code generated]
  ./node_modules/bs-platform/lib/js/caml_js_exceptions.js 641 bytes [built] [code generated]
  ./node_modules/bs-platform/lib/js/curry.js 11.9 KiB [built] [code generated]
  ./node_modules/bs-platform/lib/js/caml_option.js 1.5 KiB [built] [code generated]
  ./node_modules/bs-platform/lib/js/caml_exceptions.js 492 bytes [built] [code generated]
  ./node_modules/bs-platform/lib/js/caml_array.js 2.17 KiB [built] [code generated]
modules by path ./src/ 1.08 KiB
  ./src/AVeryBigSum.bs.js 629 bytes [built] [code generated]
  ./src/utils/Readline.bs.js 476 bytes [built] [code generated]
external "readline" 42 bytes [built] [code generated]
webpack 5.72.1 compiled successfully in 915 ms
```

### Submit to HackerRank
If everything successfully built and packaged then the output of `dist/main.js` should be ready for HackerRank. Example:
![It may look like word vomit, but isn't it too adorable not to love?](img/submit-to-hackerrank.png)

# But doesn't that mean there are answers to hackerrank in here?
Yes, and they're a billion other places online. I'm not here to police other people on how they're using this code, please be responsible and do not use it to cheat. 

TODO: Create a template of this project from an earlier commit, this is my repo to work out of for now.

# VSCode OCaml Platform extension troubleshooting
If you're having any issues with the [OCaml Platform extension](https://github.com/ocamllabs/vscode-ocaml-platform) (used to hook VSCode up to the [`ocaml-lsp-server`](https://github.com/ocaml/ocaml-lsp) for intellisense-y goodness) here are a few things worth trying:

### 0. NPM Install
If you haven't yet run it on your local copy of this repo you need to before doing any further troubleshooting:
```sh
$ npm install
```

### 1. Version check
You should be running on version 4.06 of the ocaml compiler:
```sh
$ opam switch list
#  switch   compiler                    description
   4.06.1   ocaml-base-compiler.4.06.1  4.06.1
→  4.12.0   ocaml-base-compiler.4.12.0  4.12.0
   4.14.0   ocaml-base-compiler.4.14.0  4.14.0
   default  ocaml-system.4.08.1         default
```

If you have 4.06 available but not active, you can activate it (use your version number):
```sh
$ opam switch 4.06.1
```

If it wasn't installed, install it with:
```sh
$ opam switch create 4.06.1
```

### 2. LSP pre-reqs
Make sure lsp and lspformat (and/or lspformat-rpc) are installed
TODO: rest of this one

### 3. LSP error logs
Check error messages in LSP by enabling them and all that
TODO: rest of this one too

# Can't resolve 'blah.bs.js' in 'path'
Make sure you're running the `hackify` command with a path that is exact. `src/File.bs.js` will fail, while `./src/File.bs.js` will work:
```sh
$ npm run hackify src/DiagonalDifference.bs.js 

> hackerrank-reasonm@0.1.0 prehackify
> npm run build


> hackerrank-reasonm@0.1.0 build
> bsb -make-world

bsb: no work to do.
[3/3] Building src/DiagonalDifference.cmj

> hackerrank-reasonm@0.1.0 hackify
> npx webpack build -t "node" --mode production --entry  "src/DiagonalDifference.bs.js"

assets by status 0 bytes [cached] 1 asset

ERROR in main
Module not found: Error: Can't resolve 'src/DiagonalDifference.bs.js' in '/Users/paul/git/_sandbox/hackerrank-reasonml'
Did you mean './src/DiagonalDifference.bs.js'?
Requests that should resolve in the current directory need to start with './'.
Requests that start with a name are treated as module requests and resolve within module directories (node_modules).
If changing the source code is not an option there is also a resolve options called 'preferRelative' which tries to resolve these kind of requests in the current directory too.
resolve 'src/DiagonalDifference.bs.js' in '/Users/paul/git/_sandbox/hackerrank-reasonml'
  Parsed request is a module
  using description file: /Users/paul/git/_sandbox/hackerrank-reasonml/package.json (relative path: .)
    resolve as module
      looking for modules in /Users/paul/git/_sandbox/hackerrank-reasonml/node_modules
        /Users/paul/git/_sandbox/hackerrank-reasonml/node_modules/src doesn't exist
      /Users/paul/git/_sandbox/node_modules doesn't exist or is not a directory
      /Users/paul/git/node_modules doesn't exist or is not a directory
      /Users/paul/node_modules doesn't exist or is not a directory
      /Users/node_modules doesn't exist or is not a directory
      /node_modules doesn't exist or is not a directory

webpack 5.72.1 compiled with 1 error in 96 ms
$ npm run hackify ./src/DiagonalDifference.bs.js

> hackerrank-reasonm@0.1.0 prehackify
> npm run build


> hackerrank-reasonm@0.1.0 build
> bsb -make-world

bsb: no work to do.
bsb: no work to do.

> hackerrank-reasonm@0.1.0 hackify
> npx webpack build -t "node" --mode production --entry  "./src/DiagonalDifference.bs.js"

asset main.js 38.3 KiB [emitted] [minimized] (name: main)
modules by path ./node_modules/bs-platform/lib/js/*.js 94.6 KiB
  ./node_modules/bs-platform/lib/js/caml_array.js 2.24 KiB [built] [code generated]
  ./node_modules/bs-platform/lib/js/pervasives.js 17.4 KiB [built] [code generated]
  ./node_modules/bs-platform/lib/js/caml_format.js 19.4 KiB [built] [code generated]
  ./node_modules/bs-platform/lib/js/curry.js 11.9 KiB [built] [code generated]
  ./node_modules/bs-platform/lib/js/js_list.js 5.18 KiB [built] [code generated]
  ./node_modules/bs-platform/lib/js/caml_io.js 1.81 KiB [built] [code generated]
  ./node_modules/bs-platform/lib/js/caml_sys.js 2.23 KiB [built] [code generated]
  ./node_modules/bs-platform/lib/js/caml_bytes.js 2.99 KiB [built] [code generated]
  + 9 modules
modules by path ./src/ 4.31 KiB
  ./src/DiagonalDifference.bs.js 1.77 KiB [built] [code generated]
  ./src/utils/Trelude.bs.js 901 bytes [built] [code generated]
  ./src/utils/Readline.bs.js 1.66 KiB [built] [code generated]
external "readline" 42 bytes [built] [code generated]
webpack 5.72.1 compiled successfully in 528 ms
```