using DataFrames

function main()
    errdir = "err_dir"

    df = DataFrame(file=String[],
        Score=Int[], n_WA=Int[], PlacementCost=Int[], MeasurementCost=Int[], MeasurementCount=Int[])
    props = ["Score", "Number of wrong answers", "Placement cost", "Measurement cost", "Measurement count"]

    for file in readdir(errdir)
        cols = Any["$file"]
        for line in readlines("$errdir/$file")
            for prop in props
                if startswith(line, prop)
                    push!(cols, parse(Int, line[length(prop)+4:end])) # " = " の後
                    break
                end
            end
        end
        if length(cols) == 5
            println(stderr, "Some metrics was not calculated on errlog $file.")
        else
            push!(df, cols)
        end
    end

    println(describe(df))
end

function compare()
    indir = "in"
    errdir1 = "err"
    errdir2 = "err_dir"

    df = DataFrame(L=Int[],N=Int[],S=Int[],density=Float64[],bef=Int[],aft=Int[])

    for file in readdir(indir)
        L, N, S = parse.(Int,split(readlines("$indir/$file")[1]))

        score1 = -1
        for line in readlines("$errdir1/$file")
            if startswith(line, "Score")
                score1 = parse(Int, line[length("Score")+4:end]) # " = " の後
                break
            end
        end

        score2 = -1
        for line in readlines("$errdir2/$file")
            if startswith(line, "Score")
                score2 = parse(Int, line[length("Score")+4:end]) # " = " の後
                break
            end
        end

        push!(df, [L, N, S, N / L * L, score1, score2])
    end

    increased = filter(x -> x.bef < x.aft, df)
    decreased = filter(x -> x.bef >= x.aft, df)

    println(describe(increased))
    println(describe(decreased))

    # increased = filter(x -> Score1[x] < Score2[x], eachindex(Score1))
    # decreased = filter(x -> Score1[x] >= Score2[x], eachindex(Score1))
    # for i in increased
    #     println(LNS[i])
    # end
    # println("----")
    # for i in decreased
    #     println(LNS[i])
    # end
end

main()