require "set"
require "pp"

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
        0 => [0, 1, 2, 4, 5, 6],
        1 => [2, 5],
        2 => [0, 2, 3, 4, 6],
        3 => [0, 2, 3, 5, 6],
        4 => [1, 2, 3, 5],
        5 => [0, 1, 3, 5, 6],
        6 => [0, 1, 3, 4, 5, 6],
        7 => [0, 2, 5],
        8 => [0, 1, 2, 3, 4, 5, 6],
        9 => [0, 1, 2, 3, 5, 6]
    }

    full_digits = [
        [0, 1, 2, 4, 5, 6].join,
        [2, 5].join,
        [0, 2, 3, 4, 6].join,
        [0, 2, 3, 5, 6].join,
        [1, 2, 3, 5].join,
        [0, 1, 3, 5, 6].join,
        [0, 1, 3, 4, 5, 6].join,
        [0, 2, 5].join,
        [0, 1, 2, 3, 4, 5, 6].join,
        [0, 1, 2, 3, 5, 6].join
    ]

    digits_length = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6]

    digits_by_length = {
        2 => [1],
        3 => [7],
        4 => [4],
        5 => [2, 3, 5],
        6 => [0, 6, 9],
        7 => [8]        
    }

    segment_fingerprints = (0..6).map {
        |i|
        picked = digits
            .select { |_, segments| segments.include? i }
            .keys
            .map { |i| digits_length[i] }
            .sort! { |a, b| a <=> b }

        [("a"[0].ord + i).chr, picked.join("")]
    }

    line = read_line

    if line == "" then return -1 end

    signals, output = line.split("|").map { |s| s.strip }

    signals = signals.split(" ").map { |s| s.strip }
    output = output.split(" ").map { |s| s.strip }

    shuffled_digits = signals.map { |signal| signal.split("").map { |c| c[0].ord - "a"[0].ord } }

    shuffled_segment_fingerprints = (0..6).map {
        |i|
        picked = shuffled_digits.select { |arr| arr.include? i }.map { |arr| arr.length }.sort! { |a, b| a <=> b }

        [("a"[0].ord + i).chr, picked.join("")]
    }

    segment_fingerprints.sort! { |a, b| a[1] <=> b[1] }
    shuffled_segment_fingerprints.sort! { |a, b| a[1] <=> b[1] }
    
    mapped = {}

    (0..6).each {
        |i|

        mapped[shuffled_segment_fingerprints[i][0]] = segment_fingerprints[i][0]
    }

    result = output.map {
        |signal|

        decoded_signal = signal.split("").map {
            |c|

            decoded = mapped[c]

            decoded[0].ord - "a"[0].ord
        }.sort! { |a, b| a <=> b }.join("")

        segment_index = full_digits.find_index(decoded_signal)

        segment_index
    }.join("").to_i

    result
end

sum = 0

loop do
    connections = read_wire_connection
    break if connections == -1
    sum += connections
end

puts sum
