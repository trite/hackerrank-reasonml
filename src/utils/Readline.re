// Modified/updated slightly from the original code here:
//   https://github.com/kfish610/bs-readline/blob/master/src/Readline.re

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

let readline = (callback) => {
    rl##on("line", (data) => {
        callback(data);
    });
};

let close = () => {
    rl##close();
};

let read: unit => string = () => {
    let result = ref("");

    readline(current => {result := current});

    result.contents
};

let readClose: unit => string = () => {
    let result = read();

    close();

    result
}