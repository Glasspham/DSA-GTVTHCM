**Dãy số được thêm vào cây theo thứ tự:**  
`50, 18, 35, 14, 90, -5, 10, 15, 35, 55, 65, 52`

### **A. Xây dựng cây BST**
#### 1. **Thêm 50** → Gốc của cây là `50`.
```
50
```

#### 2. **Thêm 18** → `18 < 50`, Là con trái của `50`.
```
   50
  /
18
```

#### 3. **Thêm 35** → `35 < 50`, `35 > 18`, Là con phải của `18`.
```
   50
  /
18
  \
   35
```

#### 4. **Thêm 14** → `14 < 50`, `14 < 18`, Là con trái của `18`.
```
      50
     /
   18
  /  \
14    35
```

#### 5. **Thêm 90** → `90 > 50`, Là con phải của `50`.
```
      50
     /  \
   18    90
  /  \
14    35
```

#### 6. **Thêm -5** → `-5 < 50`, `-5 < 18`, `-5 < 14`, Là con trái của `14`.
```
         50
        /  \
      18    90
     /  \
   14    35
  /
-5
```

#### 7. **Thêm 10** → `10 < 50`, `10 < 18`, `10 < 14`, `10 > -5`, Là con phải của `-5`.
```
         50
        /  \
      18    90
     /  \
   14    35
  /
-5
  \
   10
```

#### 8. **Thêm 15** → `15 < 50`, `15 < 18`, `15 > 14`, Là con phải của `14`.
```
         50
        /  \
      18    90
     /  \
   14    35
  /     /
-5    15
  \
   10
```

#### 9. **Thêm 35 (trùng)** → BST có thể chứa các số trùng lặp hoặc bỏ qua. Nếu chấp nhận, 35 được chèn vào bên phải của 35 trước đó.
```
         50
        /  \
      18    90
     /  \
   14    35
  /  \     \
-5    15    35
  \
   10
```

#### 10. **Thêm 55** → `55 > 50`, `55 < 90`, Là con trái của `90`.
```
            50
        /        \
      18          90
     /  \        /
   14    35    55
  /  \     \
-5    15    35
  \
   10
```

#### 11. **Thêm 65** → `65 > 50`, `65 < 90`, `65 > 55`, Là con phải của `55`.
```
            50
        /        \
      18          90
     /  \        /
   14    35    55
  /  \     \     \
-5    15    35    65
  \
   10
```

#### 12. **Thêm 52** → `52 > 50`, `52 < 90`, `52 < 55`, Là con trái của `55`.
```
               50
        /              \
      18                90
     /  \              /
   14    35          55
  /  \     \        /  \
-5    15    35    52    65
  \
   10
```


### **B. Xây dựng cây AVL**
#### 1. **Thêm 50** → Gốc của cây là `50`.  
```
50
```
→ Cân bằng.

#### 2. **Thêm 18** → `18 < 50`, → Là con trái của `50`.
```
   50
  /
18
```
→ Cân bằng.

#### 3. **Thêm 35** → `35 < 50`, `35 > 18` → Là con phải của `18`
```
   50
  /
18
  \
  35
```
→ Mất cân bằng tại 50 (Trái-Phải)

→ xoay trái tại 18 
```
      50
     /
   35
  /
18
```
→ xoay phải tại 50
```
   35
  /  \
18    50
```
→ Cân bằng

#### 4. **Thêm 14** → `14 < 35`, `14 < 18` → Là con trái của `18`
```
      35
     /  \
   18    50
  /
14
```
→ Cân bằng

#### 5. **Thêm 90** → `90 > 35`, `90 > 50` → Là con phải của `50`
```
      35
     /  \
   18    50
  /        \
14          90
```
→ Cân bằng

#### 6. **Thêm -5** →`-5 < 35`, `-5 < 18`, `-5 < 14` → Là con trái của `14`
```
         35
        /  \
      18    50
     /        \
   14          90
  /
-5
```
→ Mất cân bằng tại 18 (Trái - Trái).

→ Xoay phải tại 18
```
      35
     /  \
   14    50
  /  \     \
-5    18    90
```
→ Cân bằng

#### 7. **Thêm 10** → `10 < 35`, `10 < 14`, `10 > -5` → Là con phải của `-5`  
```
      35
     /  \
   14    50
  /  \     \
-5    18    90
  \
   10
```
→ Cân bằng

#### 8. **Thêm 15** → `15 < 35`, `15 > 14`, `15 < 18` → Là con trái của `18`  
```
        35
       /  \
     14    50
  /      \   \
-5        18  90
  \      /
   10  15
```
→ Cân bằng

#### 9. **Thêm 35** → (bị trùng, bỏ qua)

#### 10. **Thêm 55** → `55 > 35`, `55 > 50`, `55 < 90` → Là con trái của `90`  
```
        35
       /  \
     14    50
  /      \   \
-5        18  90
  \      /   /
   10  15  55
```
→ Mất cân bằng tại 50 (Phải - Trái).

→ Xoay phải tại 90
```
        35
       /  \
     14    50
  /      \   \
-5        18  55
  \      /      \
   10  15        90
```
→ Xoay ttrái tại 50
```
           35
       /        \
     14          55
  /      \      /  \
-5        18  50    90
  \      /
   10  15
```
→ Cân bằng

#### 11. **Thêm 65** → `65 > 35`, `65 > 55`, `65 < 90` → Là con trái của `90`  
```
           35
       /        \
     14          55
  /      \      /  \
-5        18  50    90
  \      /         /
   10  15        65
```
→ Cân bằng

#### 12. **Thêm 52** → `52 > 35`, `52 < 55`, `52 > 50` → Là con phải của `50`  
```
            35
       /          \
     14            55
  /      \      /      \
-5        18  50        90
            35
       /          \
     14            55
  /      \      /      \
-5        18  50        65
  \      /      \
   10  15        52
```
→ Cân bằng

---

**Dãy số được thêm vào cây theo thứ tự:**  
`65, 35, 51, 26, 90, -12, 18, 30, 37, 29, 63, 1`

### **A. Xây dựng cây BST**
#### 1. **Thêm 65** → Gốc của cây là `65`.
```
65
```

#### 2. **Thêm 35** → `35 < 65`, Là con trái của `65`.
```
  65
 /
35
```

#### 3. **Thêm 51** → `51 < 65`, `51 > 35`, Là con phải của `35`.
```
  65
 /
35
  \
  51
```

#### 4. **Thêm 26** → `26 < 65`, `26 < 35`, Là con trái của `35`.
```
   65
  /
35
/  \
26  51
```

#### 5. **Thêm 90** → `90 > 65`, Là con phải của `65`.
```
   65
  /  \
35   90
/  \
26  51
```

#### 6. **Thêm -12** → `-12 < 65`, `-12 < 35`, `-12 < 26`, Là con trái của `26`.
```
     65
    /  \
  35   90
 /  \
26  51
/
-12
```

#### 7. **Thêm 18** → `18 < 65`, `18 < 35`, `18 < 26`, `18 > -12`, Là con phải của `-12`.
```
     65
    /  \
  35   90
 /  \
26  51
/
-12
   \
   18
```

#### 8. **Thêm 30** → `30 < 65`, `30 < 35`, `30 > 26`, Là con phải của `26`.
```
     65
    /  \
  35   90
 /  \
26  51
/ \
-12 30
   \
   18
```

#### 9. **Thêm 37** → `37 < 65`, `37 > 35`, `37 < 51`, Là con trái của `51`.
```
     65
    /  \
  35   90
 /  \
26  51
/ \  /
-12 30 37
   \
   18
```

#### 10. **Thêm 29** → `29 < 65`, `29 < 35`, `29 > 26`, `29 < 30`, Là con trái của `30`.
```
     65
    /  \
  35   90
 /  \
26  51
/ \  /
-12 30 37
   / \
 29  18
```

#### 11. **Thêm 63** → `63 < 65`, `63 > 35`, `63 > 51`, `63 > 37`, Là con phải của `37`.
```
     65
    /  \
  35   90
 /  \
26  51
/ \  /
-12 30 37
   / \  \
 29  18 63
```

#### 12. **Thêm 1** → `1 < 65`, `1 < 35`, `1 < 26`, `1 > -12`, `1 < 18`, Là con trái của `18`.
```
     65
    /  \
  35   90
 /  \
26  51
/ \  /
-12 30 37
   / \  \
 29  18 63
     /
    1
```

### **B. Xây dựng cây AVL**
#### 1. **Thêm 65** → Gốc của cây là `65`.
```
65
```
→ Cân bằng.

#### 2. **Thêm 35** → `35 < 65`, Là con trái của `65`.
```
  65
 /
35
```
→ Cân bằng.

#### 3. **Thêm 51** → `51 < 65`, `51 > 35`, Là con phải của `35`.
```
  65
 /
35
  \
  51
```
→ Cân bằng.

#### 4. **Thêm 26** → `26 < 65`, `26 < 35`, Là con trái của `35`.
```
   65
  /
35
/  \
26  51
```
→ Cân bằng.

#### 5. **Thêm 90** → `90 > 65`, Là con phải của `65`.
```
   65
  /  \
35   90
/  \
26  51
```
→ Cân bằng.

#### 6. **Thêm -12** → `-12 < 65`, `-12 < 35`, `-12 < 26`, Là con trái của `26`.
```
     65
    /  \
  35   90
 /  \
26  51
/
-12
```
→ Mất cân bằng tại 35 (Trái-Trái).
→ Xoay phải tại 35.
```
     65
    /  \
  26   90
 /  \
-12 35
      \
      51
```
→ Cân bằng.

#### 7. **Thêm 18** → `18 < 65`, `18 < 26`, `18 > -12`, Là con phải của `-12`.
```
     65
    /  \
  26   90
 /  \
-12 35
   \   \
   18  51
```
→ Cân bằng.

#### 8. **Thêm 30** → `30 < 65`, `30 > 26`, Là con phải của `26`.
```
     65
    /  \
  26   90
 /  \
-12 35
   \   \
   18  51
      /
     30
```
→ Mất cân bằng tại 35 (Trái).
→ Xoay trái tại 35.
```
     65
    /  \
  26   90
 /  \
-12  30
   \    \
   18   35
           \
           51
```
→ Cân bằng.

#### 9. **Thêm 37** → `37 < 65`, `37 > 26`, `37 > 30`, `37 > 35`, `37 < 51`, Là con trái của `51`.
```
     65
    /  \
  26   90
 /  \
-12  30
   \    \
   18   35
           \
           51
          /
         37
```
→ Cân bằng.

#### 10. **Thêm 29** → `29 < 65`, `29 > 26`, `29 < 30`, Là con trái của `30`.
```
     65
    /  \
  26   90
 /  \
-12  30
   \    \
   18   35
      /    \
     29    51
           /
          37
```
→ Cân bằng.

#### 11. **Thêm 63** → `63 < 65`, `63 > 26`, `63 > 30`, `63 > 35`, `63 > 51`, `63 > 37`, Là con phải của `37`.
```
     65
    /  \
  26   90
 /  \
-12  30
   \    \
   18   35
      /    \
     29    51
           /
          37
            \
            63
```
→ Mất cân bằng tại 51 (Phải-Phải).
→ Xoay trái tại 51.
```
     65
    /  \
  26   90
 /  \
-12  30
   \    \
   18   35
      /    \
     29    37
           /  \
          51  63
```
→ Cân bằng.

#### 12. **Thêm 1** → `1 < 65`, `1 < 26`, `1 > -12`, `1 < 18`, Là con trái của `18`.
```
     65
    /  \
  26   90
 /  \
-12  30
   \    \
   18   35
  /   /    \
 1   29    37
           /  \
          51  63
```
→ Cân bằng.

#### 13. **Xóa 90**
- 90 là nút lá, chỉ cần xóa trực tiếp.
```
     65
    /  \
  26   (rỗng)
 /  \
-12  30
   \    \
   18   35
  /   /    \
 1   29    37
           /  \
          51  63
```
→ Cân bằng.