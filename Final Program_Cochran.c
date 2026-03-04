#include <stdio.h>

//manager fixed salary
double managerpay() {
    double salary;
    printf("Manager's weekly salary: $");
    scanf("%lf", &salary);
    return salary;  
}

//hourly plus overtime 
 double hourlypay(double hours, double rate) {
    double gross;
    if (hours <= 40)
        gross = hours * rate;
    else
        gross = 40 * rate + (hours - 40) * rate * 1.5;
    return gross;
}

//commision 
double commissionpay() {
    double sales;
    printf("Enter gross weekly sales: $");
    scanf("%lf", &sales);

    double gross = 375 + 0.072 * sales; 
    return gross;
}


int main() {
const double tax_rate=0.09275;
const int Total_employees = 23;

int employeeId[Total_employees], paycode[Total_employees], insurance_choice[Total_employees], insurance_type[Total_employees];

double gross_pay[Total_employees], taxes_paid[Total_employees], net_pay[Total_employees], hours_worked[Total_employees], hourly_rate[Total_employees], insurance_cost[Total_employees];

double total_company_net= 0.0;

//Account for 23 Employees 
for (int i = 0; i < Total_employees; i++) {
 printf("\n Employee %d \n", i + 1);

//Employee ID
printf("Enter employee ID: ");
       scanf("%d", &employeeId[i]);

//paycode
printf("Enter paycode (1=Manager, 2=Hourly, 3=Commission): ");
scanf("%d", &paycode[i]);

//Insurance
printf("Do you want insurance? 1=Yes, 2=No: ");
scanf("%d", &insurance_choice[i]);
if (insurance_choice[i] == 1) {
    printf("Select Insurance plan 1=Single, 2=Family: ");
    scanf("%d", &insurance_type[i]);
    if (insurance_type[i] == 1)
    insurance_cost[i] = 50.0;
    else
        insurance_cost[i] = 115.0;
} else {
    insurance_cost[i] = 0.0;
}


//switch
switch (paycode[i]) {
case 1:
        gross_pay[i] = managerpay();
        break;

case 2: //store in array
printf("Enter hours worked: ");
    scanf("%lf", &hours_worked[i]);        
    printf("Enter hourly rate: $");
    scanf("%lf", &hourly_rate[i]);         

gross_pay[i] = hourlypay(hours_worked[i], hourly_rate[i]);  
break;

case 3:
        gross_pay[i] = commissionpay();
        break;
default:
        printf("Invalid paycode\n");
        gross_pay[i] = 0.0;
        break;
}

//outputs 
taxes_paid[i] = gross_pay[i] * tax_rate;
net_pay[i] = gross_pay[i] - taxes_paid[i] - insurance_cost[i];
total_company_net += net_pay[i];


//employee pay info
printf("\nEmployee ID: %d\n", employeeId[i]);
if (paycode[i] == 2) {
printf("Hours Worked: %.2lf\n", hours_worked[i]);
}
printf("Gross Pay: $%.2lf\n", gross_pay[i]);
printf("Taxes Paid: $%.2lf\n", taxes_paid[i]);
printf("Insurance Cost: $%.2lf\n", insurance_cost[i]);
printf("Net Pay: $%.2lf\n", net_pay[i]);


//totals so far
    printf("\n");
    printf("Total Net Pay so far: $%.2lf", total_company_net);
    printf("\n");

}
//totals
    printf("Company Pay:\n");
    printf("Total Net Pay: $%.2lf", total_company_net);
    
    return 0;
}

