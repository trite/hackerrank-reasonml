// https://www.hackerrank.com/challenges/a-very-big-sum/problem
// open Trelude;

// Readline.readLineCallback(_ => {
//   Readline.readLineCallback(line2 => {
//     line2
//     |> Js.String.split(" ")
//     |> Js.Array.map(Int64.of_string)
//     |> Js.Array.reduce(Int64.add, 0L)
//     |> Int64.to_string
//     |> Js.log;

//     Readline.close();
//   });
// });

// let doWork: array(string) => unit = (arr) =>
//   arr[1]
//   |> Js.String.split(" ")
//   |> Js.Array.map(Int64.of_string)
//   |> Js.Array.reduce(Int64.add, 0L)
//   |> Int64.to_string
//   |> Js.log;
// Readline.readLines(2, true, doWork);

Readline.readLines(2, true, (arr) =>
  arr[1]
  |> Js.String.split(" ")
  |> Js.Array.map(Int64.of_string)
  |> Js.Array.reduce(Int64.add, 0L)
  |> Int64.to_string
  |> Js.log
);
