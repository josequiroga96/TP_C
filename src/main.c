
#include "stdio.h"
#include "Ex1/Manufacturer.h"
#include "Ex1/Provider.h"
#include "Ex1/Catalogue.h"
#include "Ex1/LineCart.h"
#include "Ex1/Cart.h"
#include "Ex2/Manufacturer2.h"
#include "Ex2/Provider2.h"
#include "Ex2/LineSale.h"
#include "Ex2/Sale.h"
#include "Ex2/RegisteredUser.h"
#include "Ex3/Material.h"
#include "Ex3/Library.h"


static void testEx1(){
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

    Accessory* accessory1 = makeAccessory("Lente", 63, 23, "hshs", 823);
    Camera* camera1 = makeCamera("Camera", 23, 313, 2323, 3424, 34,2343);

    Provider2* provider21= createProvider2("Carlos", "khdhs", "jksjf", "khbdak", "hdshkd", 4343, 1234134332, 9823423);

    provideAccesory(provider21, 67, accessory1->name, accessory1->code, accessory1->type, "bskh", accessory1->price);
    provideCamera(provider21, 34, camera1->name, camera1->code, camera1->megaPixels, camera1->screenSize, camera1->opticalZoom, camera1->type, camera1->price);

    LineSale* lineSale1 = createAccessoryLineSale(324,43,accessory1);
    LineSale* lineSale2 = createCameraLineSale(243, 13, camera1);

    Sale* sale1 = createSale(24,43,34);

    addAccessory(sale1, accessory1, lineSale1->quantity);
    addCamera(sale1, camera1, lineSale2->quantity);

    RegisteredUser* registeredUser1 = createRegisteredUser("hjsdhj", 453, "hsfs", 8928924, "hsjbhd", "ifhs", "hdbhd", 7823, 1);

    buyProducts(registeredUser1, sale1);

    printf("El precio del accesorio es: ");
    printf("%i \n \n", registeredUser1->sales[0]->lineSale[0]->accessory->price);
}

static void testEx3(){
    printf("\n Exercise 3: \n");

    Material* material1 = createBook(232, "asdas", "nkds", 98, "dj", "jdj");
    Material* material2 = createMagazine(9, "jdjd", "jds", 83, "jsj", "si");

    Person* person1 = createStudent("sdf", "adf", "jdjd", 984,94924);
    Person* person2 = createTeacher("sds", "idid", "kxk", 8484, 828282);

    Library* library1 = createLibrary(84, 23);

    addPerson(library1, person1);
    addPerson(library1, person2);

    addMaterial(library1, material1);
    addMaterial(library1, material2);

    Borrowing* borrowing1 = make_Borrowing(library1, person1, 0, material1->code, "hjh", "jdjd");

    printf("\n");
}

static void testEx4(){
    printf("\n Exercise 4: \n");
}

static void testEx5(){
    printf("\n Exercise 5: \n");
}

int main(){
    testEx1();
    testEx2();
    testEx3();
    testEx4();
    testEx5();

    printf("Hello world");

}


