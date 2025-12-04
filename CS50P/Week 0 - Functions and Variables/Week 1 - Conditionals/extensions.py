from collections import defaultdict

def file_ending(fileName):
    parts = fileName.rsplit(".", 1)
    mimes = defaultdict(lambda: "application/octet-stream", {
        "gif": "image/gif",
        "jpg": "image/jpeg",
        "jpeg": "image/jpeg",
        "png": "image/png",
        "pdf": "application/pdf",
        "txt": "text/plain",
        "zip": "application/zip"
    })

    if len(parts) == 2:
        return eval("mimes")[parts[1].lower().strip()]
    else:
        return "application/octet-stream"

def main():
    file_name = input("FileName: ")
    file_end = file_ending(file_name)
    print(file_end)

if __name__ == "__main__":
    main()
