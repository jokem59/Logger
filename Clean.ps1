Param(
    [switch]$build = $false,
    [switch]$bin = $false
)

if ($build -eq $true)
{
    Remove-Item ./build/* -Recurse;
}

if ($bin -eq $true)
{
    Remote-Item ./bin/* -Recurse;
}
