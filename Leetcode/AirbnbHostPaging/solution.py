def paging(records = [], k = 0):
    pages = []
    cur_page = 0
    host_pos = {}

    pages.append(list())

    for record in records:
        if record[0] not in host_pos:
            pages[cur_page].append(record)
            host_pos[record[0]] = cur_page
        else:
            location = host_pos[record[0]]
            location += 1
            while location != len(pages) and len(pages[location]) == k:
                location += 1

            if location == len(pages):
                pages.append(list())
            pages[location].append(record)
            host_pos[record[0]] = location

    while len(pages[cur_page]) == k:
        cur_page += 1
        if cur_page == len(pages):
            pages.append(list())

    print pages
