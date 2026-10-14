int __cdecl fclose_if_open(FILE *file)

{
  int iVar1;
  
  if (file != (FILE *)0x0) {
    iVar1 = fclose((FILE *)file);
    return iVar1;
  }
  return -1;
}

