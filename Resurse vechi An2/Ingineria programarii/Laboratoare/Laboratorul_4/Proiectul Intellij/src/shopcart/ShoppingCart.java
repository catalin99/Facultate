package shopcart;

import java.util.List;

public class ShoppingCart {
	private float totalPrice;
	private List<Product> listaProduse;
	ShoppingCart(List<Product> listaProduse)
	{
		this.listaProduse=listaProduse;
	}
	public float getPriceForOneTypeOfProduct(Product product)
	{
		int count=0;
		for(Product i: listaProduse)
		{
			if(i.getBarcode()==product.getBarcode())
			{
				count++;
			}
		}
		if(count>5 && count<11)
		{
			return (float)(product.getPrice()*0.8);
		}
		else if (count>10)
		{
			return (float)(product.getPrice()*0.4);
		}
		else return (product.getPrice());
	}
	public float getPrice()
	{
		for(Product i : listaProduse)
		{
			totalPrice+=getPriceForOneTypeOfProduct(i);
		}
		return (float)totalPrice;
	}
}
