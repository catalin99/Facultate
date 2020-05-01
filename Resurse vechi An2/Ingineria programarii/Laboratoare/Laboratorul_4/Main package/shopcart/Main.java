package shopcart;

public class Main {

	public static void main(String[] args) {
		Product produs1=new Product("mar",3,1234);
		Product produs2=new Product("computer",100,123);
		Product produs3= new Product("par",10,12);
		Client client=new Client();
		client.addProduct(produs1);//3
		client.addProduct(produs2,7);//560
		client.addProduct(produs3,30);
		client.removeProduct(produs3,10);
		ShoppingCart sc1 = new ShoppingCart(client.getProductList());
		client.confirm(sc1.getPrice());
	}
}
