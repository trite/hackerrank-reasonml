// Modified/updated slightly from the original code here:
//   https://github.com/kfish610/bs-readline/blob/master/src/Readline.re
open Trelude;

type io = {.
    "input": in_channel,
    "output": out_channel
};

type rlType = {.
    [@bs.meth]
    "close": unit => unit,

    [@bs.meth]
    "write": string => unit,

    [@bs.meth]
    "on": (string, string => unit) => unit
};

// Providing an empty string produces a compiler warning now
[@bs.module "readline"]
external createInterface : io => rlType = "createInterface";

let rl = createInterface({
    "input": [%raw "process.stdin"],
    "output": [%raw "process.stdout"]
});

let readLine = (f) => {
    rl##on("line", (data) => {
        f(data);
    });
};

let close = () => {
    rl##close();
};

let rec readLines = (count, acc, isDone, f) =>
  count <= 0
  ? {
    f(acc |> Js.List.rev |> Js.List.toVector);
    if (isDone) {
      close();
    }
  }
  : readLine(line => 
    readLines(count-1, line ^: acc, isDone, f)
  );

// :-( Soon I'll be more familiar with the right way to do this I hope!
let readLines = (count, close, f) =>
  readLines(count, [], close, f);