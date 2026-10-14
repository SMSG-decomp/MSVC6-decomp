char * __cdecl int64_to_string(int *value,char *buffer,int radix,int is_unsigned)

{
  int negative;
  
  if ((((is_unsigned == 0) && (radix == 10)) && (value[1] < 1)) && (value[1] < 0)) {
    negative = 1;
  }
  else {
    negative = 0;
  }
  int64_to_digits(value,buffer,radix,negative);
  return buffer;
}

