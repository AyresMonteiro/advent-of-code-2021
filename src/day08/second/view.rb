
def print_display(digits)
    print "\e[1m"
    i = 0

    length = digits.length

    while i < 7
        j = 0

        while j < length
            digit = digits[j]

            if i == 0 then
                if digit.include? "a" then
                    print " ---- "
                else
                    print "      "
                end
            end

            if i == 1 or i == 2 then
                has_b = digit.include? "b"
                has_c = digit.include? "c"

                if has_b and has_c then
                    print "|    |"
                elsif has_b then
                    print "|     "
                elsif has_c then
                    print "     |"
                else
                    print "      "
                end
            end

            if i == 3 then
                if digit.include? "d" then
                    print " ---- "
                else
                    print "      "
                end
            end

            if i == 4 or i == 5 then
                has_e = digit.include? "e"
                has_f = digit.include? "f"

                if has_e and has_f then
                    print "|    |"
                elsif has_e then
                    print "|     "
                elsif has_f then
                    print "     |"
                else
                    print "      "
                end
            end

            if i == 6 then
                if digit.include? "g" then
                    print " ---- "
                else
                    print "      "
                end
            end


            j += 1

            print " "
        end

        print "\n"

        i += 1
    end

    print "\e[22m"
end

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

original_digits = [
    ["abcefg", "cf", "acdeg", "acdfg", "bcdf"],
    ["abdfg", "abdefg", "acf", "abcdefg", "abcdfg"]
]

found = ("a".."g").map do |c|
    original_digits.flatten.select { |d| d.include? c }.sort!
end

def find_duplicates(array)
    array.select { |e| array.count(e) > 1 }.uniq
end

has_duplicated_sets = find_duplicates(found).length

puts "There are no duplicated sets!"

puts "
Because there are no duplicates, we can safely
assume  that  the  digits  are  unique sets of
segments  and because of that, we can generate
a  fingerprint  for  each  segment  using  the
digits that contain it.

But we don't have the digits when the segments
are  shuffled. We need another way to identify
them.

The information of digits that is the same for
both the original and the shuffled ones is the
number of segments that each digit has.

So,  we  can  generate  a  fingerprint for the
segment  using  the  number  of  segments  for
each digit.

By  doing  that, we can map each signal from 0
to 6 to a segment fingerprint.
".strip

print "\n\n"

line = read_line

unique, displayed = line.split("|")

unique = unique.strip.split(" ").map { |i| i.strip }
displayed = displayed.strip.split(" ").map { |i| i.strip }

unique = unique.each_slice(5).to_a

original_digits.each do |digits|
    print_display(digits)
end

puts "\n\nShuffled:\n\n\n"

unique.each do |digits|
    print_display(digits)
end
