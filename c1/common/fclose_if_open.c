int __cdecl fclose_if_open(FILE *f)

{
  int iVar1;
  
  if (f != (FILE *)0x0) {
    iVar1 = fclose(f);
    return iVar1;
  }
  return -1;
}

