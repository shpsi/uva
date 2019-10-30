
import java.math.BigInteger;
import java.util.Collections;
import java.util.Scanner;
import java.util.Set;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.stream.Collectors;

public class FilterUtils {

  public static void main(String args[])
  {
    Scanner scan = new Scanner(System.in);
    int n = scan.nextInt();

    BigInteger answer = new BigInteger("0");
    BigInteger[] array = new BigInteger[2001];
    for(int i = 0; i < 2001; i++)
      array[i] = new BigInteger("0");

    BigInteger constTwo = new BigInteger("2");

    for(int i = 0; i < n; i++)
    {
      String s = scan.next();
      int x = scan.nextInt();

      if(s.equals("win"))
        array[x] = answer.add(constTwo.pow(x));
      else
        answer = array[x].max(answer);
    }

    System.out.println(answer);
  }
}
