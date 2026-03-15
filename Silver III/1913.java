import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int target = Integer.parseInt(br.readLine());
        int[][] arr = new int[n][n];

        int dx[] = { 0, 1, 0, -1 };
        int dy[] = { 1, 0, -1, 0 };

        int i = n * n;
        int dir = 0;
        int x = 0;
        int y = 0;
        while (i >= 1) {
            arr[y][x] = i;
            i--;
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || arr[ny][nx] != 0) {
                dir = (dir + 1) % 4;
                nx = x + dx[dir];
                ny = y + dy[dir];
            }
            x = nx;
            y = ny;
        }

        StringBuilder sb = new StringBuilder();
        for (i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sb.append(arr[i][j]).append(" ");
            }
            sb.append("\n");
        }

        for (i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == target) {
                    sb.append((i + 1)).append(" ").append((j + 1));
                }
            }
        }

        System.out.println(sb);
    }
}