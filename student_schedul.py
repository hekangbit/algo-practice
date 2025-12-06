class Solution:
    def test(self, k, chapter_list, paper_list) :
        res = []
        day = 0
        find_chapter = False
        find_paper = False
        is_need_do_paper = False

        total_chapter_left = 0
        start_do_paper = -1
        stop_do_paper = -1
        #print(len(chapter_list))
        while True:
            find_chapter = False
            find_paper = False
            for a in chapter_list:
                if a[0] == day:
                    total_chapter_left += a[1]
                    find_chapter = True
                    break
            for b in paper_list:
                if b[0] == day:
                    start_do_paper = b[0]
                    stop_do_paper = b[1]
                    find_paper = True
                    break
            if find_chapter:
                #print(a[1])
                chapter_list.remove(a)
            if find_paper:
                paper_list.remove(b)

            #print("day:", day, "total_chapter_left:", total_chapter_left)


            if day >= start_do_paper and day <= stop_do_paper:
                is_need_do_paper = True
            else :
                is_need_do_paper = False

            if total_chapter_left == 0 and is_need_do_paper == False:
                #print("insert day", day)
                res.append(day)

            if is_need_do_paper == False:
                if total_chapter_left >= k:
                    total_chapter_left -= k
                elif total_chapter_left > 0 and total_chapter_left < k:
                    total_chapter_left = 0

            if len(chapter_list) == 0 and len(paper_list) == 0 and total_chapter_left == 0:
                break
            day += 1
        return res

s = Solution()
r = s.test(3, [[9,1],[0,5],[3,6]], [[3,5]])
print(r)
