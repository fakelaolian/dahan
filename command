; -----------------------------------------------------------------------------------------
; select * from tt_user_info a left join tt_friend_info b on a.id = b.userid
; where a.age > 18 and b.age > 19 and a.city in ("a", "b")
;
; -----------------------------------------------------------------------------------------
load                &tt_user_info
load                #1%18, #2%19, #3%"a", #4%"b"
mov                 a, %alloc
open vtab           "tt_user_info"
mov                 a, <<

mov                 b, %alloc
open vtab           "tt_friend_info"
mov                 b, <<

ljoin               a, b                        ; 左连接
on                  %a%id, %b%userid            ; 关联

where:
    vtab %a:
        ge age,     #1
        in city,    #3, #4

    vtab %b:
        eq userid %a%l%id
        ge age,     #2

filter:
    vtab %a%col
    vtab %b%col