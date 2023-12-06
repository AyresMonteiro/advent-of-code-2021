def read_line
    c = ""
    line = ""

    loop do
        c = STDIN.getc
        break if c == "\n" or c == nil
        line += c
    end

    line
end

def read_wire_connection
    digits = {
        2 => [1],
        3 => [7],
        4 => [4],
        5 => [2, 3, 5],
        6 => [0, 6, 9],
        7 => [8]
    }

    line = read_line

    if line == "" then return -1 end

    signals, output = line.split("|").map { |s| s.strip }

    signals = signals.split(" ").map { |s| s.strip }
    output = output.split(" ").map { |s| s.strip }

    direct_segments = output.select do |signal|
        digits[signal.bytesize].length == 1
    end

    direct_segments.length
end

sum = 0

loop do
    connections = read_wire_connection
    break if connections == -1
    sum += connections
end

puts sum
