using StatsBase

function main()
    errdir = "err"

    Stats = map(
        file -> begin
            for line in readlines("$errdir/$file")
                if startswith(line, "Score")
                    return (file, parse(Int, line[9:end]))
                end
            end
            println(stderr, "Score is not calculated on $file.")
        end, readdir(errdir)
    )
    filter!(x -> !isnothing(x), Stats)

    Scores = map(x -> x[2], Stats)
    println("Testcase number = $(length(Scores))")
    println("Sum = $(sum(Scores))")
    println("Mean = $(mean(Scores))")
    println("Median = $(median(Scores))")
    println("Min = $(minimum(Scores))")
    println("Max = $(maximum(Scores))")
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