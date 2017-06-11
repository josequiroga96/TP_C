
#include "stdio.h"
#include "Ex1/Manufacturer.h"
#include "Ex1/Provider.h"
#include "Ex1/Catalogue.h"
#include "Ex1/LineCart.h"
#include "Ex1/Cart.h"
#include "Ex2/Manufacturer2.h"


static int testEx1(){
    printf("\n Exercise 1: \n");
    Manufacturer* manufacturer1 = createManufacturer("Juan", "Kitchen Builder", "San Martin 452", "Pilar", "www.kitchenbuilder.com", 1167325334, "Kitchen", "M01", 580);
    Manufacturer* manufacturer2 = createManufacturer("Marcelo", "Refrigerator Builder", "Av. Alsina 452", "Escobar", "www.refrigeratorbuilder.com", 1178263487, "Refrigerator", "M01", 680);
    Manufacturer* manufacturer3 = createManufacturer("Nahuel", "Microwave Builder", "Belgrano 452", "Lujan", "www.microwavebuilder.com", 1182466347, "Microwave", "M01", 480);
    Manufacturer* manufacturer4 = createManufacturer("Manuel", "Blender Builder", "Av. Antartida 452", "CABA", "www.blenderbuilder.com", 1123675362, "Blender", "M01", 210);
    Manufacturer* manufacturer5 = createManufacturer("Lucas", "Oven Builder", "General Rivas 452", "Pilar", "www.ovenbuilder.com", 1193714689, "Oven", "M01", 580);

    Provider* theProvider = createProvider("Jose", "Provider", "San Martin 452", "Pilar", "www.theprovider.com", 1167325334, 20);

    add__Product(theProvider, create_product(manufacturer1));
    add__Product(theProvider, create_product(manufacturer2));
    add__Product(theProvider, create_product(manufacturer3));
    add__Product(theProvider, create_product(manufacturer4));
    add__Product(theProvider, create_product(manufacturer5));

    Catalogue* theCatalogue = createCatalogue(01, "Catalogue", 10, 20);

    add_Product(theCatalogue, create_product(manufacturer1));
    add_Product(theCatalogue, create_product(manufacturer2));
    add_Product(theCatalogue, create_product(manufacturer3));
    add_Product(theCatalogue, create_product(manufacturer4));
    add_Product(theCatalogue, create_product(manufacturer5));

    HouseholdAppliance* auxHA = create_product(manufacturer1);

    provideHouseholdApplience(theProvider, auxHA->name, auxHA->model, 15, manufacturer1);

    LineCart* lineCart1= createLineCart(01, auxHA, 15);
    Cart* cart1= createCart(01, 20);
    addProduct(cart1, lineCart1);

    LineTicket* lineTicket1= createLineTicket(lineCart1->id, lineCart1->product, lineCart1->quantity);
    Ticket* ticket1= createTicket(cart1->id, cart1->lineCartCapacity);
    addLine(ticket1, lineTicket1);

    printf("El precio total del ticket es: ");
    printf("%i \n \n", ticket1->lineTickets[0]->product->price);
}

static void testEx2(){
    printf("\n Exercise 2: \n");

    Manufacturer2* manufacturer21= createManufacturer2("Manuel", 8932);


}

static void testEx3(){}

static void testEx4(){}

static void testEx5(){}

int main(){
    testEx1();
    testEx2();
    testEx3();
    testEx4();
    testEx5();

    printf("Hello world");

}


