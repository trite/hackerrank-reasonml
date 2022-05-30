open Trelude;

let diag1: (int, array(array(int))) => int = (len, matrix) => {
    rangeArr(0,len)
    |> Js.Array.map(x => matrix[x][x])
    |> sum
};

let diag2: (int, array(array(int))) => int = (len, matrix) => {
    rangeArr(0,len)
    |> Js.Array.map(x => matrix[len-x-1][x])
    |> sum
};

let diagAndDiff: (int, array(array(int))) => int = (len, matrix) => {
    // try to combine both diagonal checks into the same call?
};

let len =
    Readline.read()
    |> int_of_string;



// Readline.readline(len => {
//     let len = len |> int_of_string;
//     len
//     |> range(0)
//     |> Js.List.map((. x) => {
//         let result = ref ((0,0));

//         Readline.readline(currentLine => {
//             let current =
//                 currentLine
//                 |> Js.String.split(" ")
//                 |> Js.Array.map(int_of_string);

//             let y = len - x - 1;

//             result := (current[x], current[y]);

//             if (x+1 == len) {
//                 Readline.close();
//             };
//         });

//         ^result
//     })
//     |> Js.List.foldLeft((. (a1, b2), (a2, b2)) => (a1 + a2, b1 + b2), (0,0))
//     |> ignore
// });