using DataFrames

function main()
    errdir = "err"

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

main()