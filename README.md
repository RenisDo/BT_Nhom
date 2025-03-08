# Báo cáo Bài tập lớn - Nhóm 2

## 1. Thông tin nhóm

## Thông Tin Nhóm

| STT | Họ và Tên      | MSSV     | Vai Trò         |
|-----|---------------|----------|----------------|
| 1   | Trần Huy Doanh| 24022776 | Thành Viên    | 
| 2   | Phạm Ngọc Hải Đăng | 24022771 | Thành Viên | 
| 3   | Ngô Minh Giang| 24022782 | Thành Viên     | 
| 4   | Nguyễn Hoàng Hải| 24022787 | Thành Viên  | 
| 5   | Đỗ Huy Hoàng  | 24022792 | Nhóm Trưởng      | 

## 2. Thông tin bài tập

- **Knight's tour**: Trên bàn cờ NxN, con mã điểm (x, y). Tìm đường đi qua mọi ô đúng 1 lần.  
  *Gợi ý*: Đệ quy thử từng nước đi. Nếu thăm hết mọi ô, thành công. Nếu đi vào ngõ cụt, quay lui.

---

## 3. Hướng giải quyết bài toán

### a. Phân tích bài toán

Mục tiêu của bài toán là tìm một đường đi của quân mã trên bàn cờ kích thước `n x n`, sao cho quân mã có thể đi qua mỗi ô trên bàn cờ đúng một lần duy nhất.

#### **Yêu cầu đầu vào:**
- Một số nguyên dương `n` biểu thị kích thước của bàn cờ.
- Hai số nguyên `x` và `y` chỉ vị trí ban đầu của quân mã, sao cho `0 ≤ x, y < n`.

#### **Yêu cầu đầu ra:**
- Nếu có một đường đi hợp lệ, in ra bàn cờ với các nước đi từ bước 1 đến bước `n²`.
- Nếu không thể tìm ra đường đi hợp lệ, in ra thông báo `"Không tìm được đường đi"`.

#### **Ràng buộc:**
- Quân mã chỉ có thể di chuyển theo hình chữ `L`, tức là di chuyển theo một trong 8 hướng hợp lệ.
- Quân mã không được đi ra ngoài bàn cờ (`0 ≤ x, y ≤ n`).
- Không được quay lại các ô đã thăm trước đó.
- Đôi khi, không có giải pháp hợp lệ, ví dụ khi không còn nước đi hợp lệ.

### b. Thuật toán và cách tiếp cận

#### **Cách tiếp cận:**
- Bắt đầu từ vị trí `(x, y)`, quân mã sẽ thử di chuyển đến các ô hợp lệ theo từng bước.
- Nếu sau `n²` bước, quân mã đã đi qua tất cả các ô trên bàn cờ, thì bài toán được coi là đã có lời giải.
- Nếu không thể di chuyển hợp lệ, quân mã sẽ *quay lui* và thử các hướng di chuyển khác.

#### **Thuật toán quay lui:**
1. **Khởi tạo bàn cờ:**
   - Tạo một bàn cờ kích thước `n x n` với tất cả các ô được đánh dấu là chưa thăm (`-1`).

2. **Đặt quân mã tại vị trí bắt đầu:**
   - Đánh dấu bước đầu tiên tại vị trí `(x, y)` với giá trị `0`.

3. **Duyệt qua các hướng di chuyển hợp lệ của quân mã:**
   - Quân mã có thể di chuyển theo 8 hướng. Ta cần thử từng hướng này từ vị trí hiện tại.

4. **Kiểm tra tính hợp lệ của các nước đi:**
   - Nếu một nước đi hợp lệ (vị trí trong bàn cờ, chưa thăm, và hợp lệ theo quy tắc di chuyển của quân mã), ta đánh dấu bước tiếp theo tại vị trí đó và tiếp tục đệ quy thử các hướng di chuyển.

5. **Quay lui:**
   - Nếu không thể đi đến bất kỳ ô hợp lệ nào, ta quay lui và đánh dấu lại ô hiện tại là chưa thăm (`-1`), sau đó thử các hướng di chuyển khác.

6. **Kết thúc:**
   - Nếu quân mã đã đi qua tất cả các ô (`n²` bước), in ra bàn cờ với các bước đi.
   - Nếu không tìm được lời giải, in ra `"Không có nước đi thoả mãn"`.

#### c. Code:

[Source Code](./main.cpp)


### d. Ưu - Nhược điểm:

#### **Ưu điểm:**
- **Đơn giản và dễ hiểu**: Sử dụng quay lui với đệ quy giúp giải quyết vấn đề một cách trực quan.
- **Tiết kiệm bộ nhớ**: Chỉ cần một bảng 2D để theo dõi các bước đi.
- **Tính chính xác**: Tìm ra lời giải chính xác khi có thể.

#### **Nhược điểm:**
- **Tốn thời gian**: Độ phức tạp là `O(8^N)`, không hiệu quả với các bàn cờ lớn.
- **Không tối ưu**: Không sử dụng các chiến lược tìm kiếm thông minh.
- **Không xử lý nhanh khi không có lời giải**: Thử quá nhiều bước trước khi kết luận.

---

## 4. Ví dụ minh hoạ

### **Ví dụ 1**

**Input:**
```
8 0 0 (Tức là bàn cờ cỡ vừa 8x8, quân mã bắt đầu ở ô (0,0))
```

**Output:**
```
 0 59 38 33 30 17  8 63
37 34 31 60  9 62 29 16
58  1 36 39 32 27 18  7
35 48 41 26 61 10 15 28
42 57  2 49 40 23  6 19
47 50 45 54 21 14 11  4
56 43 52  3 24  5 20 13
51 46 55 44 53 22  9 12

```

**Giải thích:**
•	Quân mã được đặt ô (0,0)  -  tức ô xuất phát sẽ có giá trị là 0
•	Xét tất cả 8 hướng đi thoả mãn điều kiện của quân mã
•	Thử các tất cả các nước đi có thể từ vị trí mới này cho vào 1 list chứa cặp giá trị về số nước đi và sắp xếp tăng dần.
•	Cho quân mã đi theo các nước đi vừa sắp xếp.
•	Nếu tìm được đường đi tiếp theo và phù hợp, đánh dấu số bước và ô đã đi và đếm số bước, sau đó tiếp tục đệ quy để tìm nước đi tiếp theo
•	Nếu đi đến hết bàn cờ và thoả mãn điều kiện thì bài toán kết thúc và bài toán cho mã đi hết bàn cờ hoàn thành.
•	Nếu gặp ngõ cụt, quay lại để thử hướng đi khác và tiếp tục lặp lại quá trình trên.
•	Nếu giải được bài toán thì in ra output là nước đi quân mã, nếu không in ra màn hình " Không có nước đi thoả mãn"
•	Nếu thuật toán không tối ưu : có thể không tìm được lời giải trong thời gian hợp lí / hoặc thất bại

### **Ví dụ 2**

**Input:**
```
6 2 3 (Bàn cờ cỡ 6x6, quân mã bắt đầu ở vị trí (2,3)) 
```

**Output:**
```
25 38  9 18 3 16
32 33 10 17 2 15
39 34 11 12 7 14
40 35  8 19 4 13
41 36  5 20 21 22
42 37  6 23 24 29

```
Giải thích:
•	Quân mã bắt đầu tại ô (2, 3) - tức ô xuất phát sẽ có giá trị là 0
•	Xét tất cả 8 hướng đi thoả mãn điều kiện của quân mã
•	Thử các tất cả các nước đi có thể từ vị trí mới này cho vào 1 list chứa cặp giá trị về số nước đi và sắp xếp tăng dần.
•	Cho quân mã đi theo các nước đi vừa sắp xếp.
•	Nếu tìm được đường đi tiếp theo và phù hợp, đánh dấu số bước và ô đã đi và đếm số bước, sau đó tiếp tục đệ quy để tìm nước đi tiếp theo
•	Nếu đi đến hết bàn cờ và thoả mãn điều kiện thì bài toán kết thúc và bài toán cho mã đi hết bàn cờ hoàn thành.
•	Nếu gặp ngõ cụt, quay lại để thử hướng đi khác và tiếp tục lặp lại quá trình trên.
•	Nếu giải được bài toán thì in ra output là nước đi quân mã, nếu không in ra màn hình " Không có nước đi thoả mãn".
•	Nếu thuật toán không tối ưu : có thể không tìm được lời giải trong thời gian hợp lí / hoặc thất bại

**Ví dụ 3**

**Input:**
```
3 0 0 ( Bàn cờ cỡ 3x3, quân mã bắt đầu ở ô (0, 0), )
```

**Output:**
```
"Không có nước đi hợp lệ"
```

**Giải thích:**
•	Tạo bàn cờ cỡ 3x3
•	Quân mã bắt đầu ở ô (0, 0) nhưng không có đủ các nước đi hợp lệ để tiếp tục. Khi quân mã di chuyển, nó sẽ gặp phải ngõ cụt và không thể tiếp tục đi qua các ô còn lại mà không quay lại ô đã đi qua, khi thử cả 8 hướng đi khác nhau.
•	Từ đó, in ra màn hình " Không có nước đi thỏa mãn"

