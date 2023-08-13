using StatsBase

function print_stat(vec)
    println("Sum = $(sum(vec))")
    println("Mean = $(mean(vec))")
    println("Median = $(median(vec))")
    println("Min = $(minimum(vec))")
    println("Max = $(maximum(vec))")
end

function main()
    errdir = "err"

    Scores = map(
        file -> begin
            for line in readlines("$errdir/$file")
                if startswith(line, "Score = ")
                    return (file, parse(Int, line[9:end]))
                end
            end
            println(stderr, "Score is not calculated on $file.")
        end, readdir(errdir)
    )
    filter!(x -> !isnothing(x), Scores)

    WAs = map(
        file -> begin
            for line in readlines("$errdir/$file")
                if startswith(line, "Number of wrong answers = ")
                    return (file, parse(Int, line[27:end]))
                end
            end
            println(stderr, "Score is not calculated on $file.")
        end, readdir(errdir)
    )
    filter!(x -> !isnothing(x), WAs)

    Scores = map(x -> x[2], Scores)
    WAs = map(x -> x[2], WAs)

    println("Testcase number = $(length(Scores))")
    println("Stats of Scores: ")
    print_stat(Scores)
    println("Stats of WAs: ")
    print_stat(WAs)
end

main()

#=
function hage()
    indir = "in"
    outdir = "out"
    errdir = "err"

    Stats = Array{Tuple{String,Int}}
    sizehint!(Scores, 500)

    for file in readdir(indir)
        out_txt = read(`cargo run --release --bin tester ./main < $indir/$file > $outdir/$file`, String) # ここがオワリ
        out_txt_lines = split(out_txt, "\n")

        errsink = "$errdir/file"
        open(errsink, "a") do fp
            for line in out_txt_lines
                if startswith(line, "Score")
                    push!(Stats, (file, parse(Int, line[9:end])))
                end
                println(fp, line)
            end
        end
    end

    Scores = map(x -> x[2], Stats)
    println("Mean = $(mean(Scores))")
    println("Min = $(minimum(Scores))")
    println("Max = $(maximum(Scores))")
    println("Median = $(median(Scores))")
end
=#