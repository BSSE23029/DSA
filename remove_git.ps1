# Get the full path to the directory where the script is located
$currentDirectory = Get-Location

# Define the starting directory for the search
$startDirectory = Join-Path -Path $currentDirectory -ChildPath "ITU"

# Check if the ITU directory exists
if (-not (Test-Path -Path $startDirectory -PathType Container)) {
    Write-Host "Error: The 'ITU' directory was not found in the current location."
    Write-Host "Please run this script from your main DSA project folder."
    # Pause the script so the user can see the error before the window closes
    Read-Host -Prompt "Press Enter to exit"
    exit
}

Write-Host "Searching for .git directories inside '$startDirectory'..."

# Get all directories named '.git' recursively within the start directory
# The -Force parameter is crucial to find hidden items
$gitFolders = Get-ChildItem -Path $startDirectory -Directory -Filter ".git" -Recurse -Force

if ($gitFolders.Count -eq 0) {
    Write-Host "No .git subdirectories found. Your repository might already be clean."
} else {
    Write-Host "Found $($gitFolders.Count) .git directories to delete."
    
    # Loop through each found .git directory and delete it
    foreach ($folder in $gitFolders) {
        $folderPath = $folder.FullName
        Write-Host "Deleting: $folderPath"
        
        # The -Recurse and -Force parameters ensure it deletes the folder and all its contents
        try {
            Remove-Item -Path $folderPath -Recurse -Force -ErrorAction Stop
            Write-Host " -> Successfully deleted." -ForegroundColor Green
        }
        catch {
            Write-Host " -> FAILED to delete. Error: $_" -ForegroundColor Red
        }
    }
    
    Write-Host ""
    Write-Host "Script finished. All found .git subdirectories have been removed." -ForegroundColor Cyan
}

# Pause the script to review the output
Read-Host -Prompt "Press Enter to continue"