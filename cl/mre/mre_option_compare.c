int __cdecl mre_option_compare(char **a,char **b)

{
  int diff;
  
  diff = strcmp(*a,*b);
  return diff;
}

