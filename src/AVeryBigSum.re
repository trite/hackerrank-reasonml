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
