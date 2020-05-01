package shopcart;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Client {
	public List<Product> productList = new ArrayList<Product>();
	public void addProduct(Product produs)
	{
		productList.add(produs);
	}
	public void addProduct(Product produs,int cantitate)
	{
		for(int i=0;i<cantitate;i++){
			addProduct(produs);
		}
	}
	public void removeProduct(Product produs)
	{
		int index=0;
		for(Product i : productList)
		{
			if(i.getBarcode()==produs.getBarcode())
			{
				productList.remove(index);
				break;
			}
			index++;
		}
	}
	public void removeProduct(Product produs,int cantitate)
	{
		int count=0;
		for(Product i:productList)
		{
			if(i.getBarcode()==produs.getBarcode())
			{
				count++;
			}
		}
		if(count>=cantitate)
		{
			for(int j=0;j<cantitate;j++)
			{
				removeProduct(produs);
			}
		}
		else
		{
			for (int j=0;j<count;j++)
			{
				removeProduct(produs);
			}
		}
			
		
	}
	public boolean confirm(float totalPrice){
		boolean ok;
		Scanner scan = new Scanner(System.in);
		System.out.println("Pretul total este->" + totalPrice + " euro");
		System.out.println("Confirmati comanda?(true/false)");
		ok=scan.hasNextBoolean();
		scan.close();
		if(ok)
		{
			System.out.println("Comanda a fost realizata!");
		}
		else
		{
			System.out.println("Comanda a fost respinsa!");
		}
		return ok;
		
	}
	public List<Product> getProductList() {
		return productList;
	}
}
