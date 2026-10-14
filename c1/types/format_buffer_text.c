char * __cdecl format_buffer_text(int handle)

{
  int *piVar1;
  
  piVar1 = format_buffer_find(handle);
  if (piVar1 == (int *)0x0) {
    return (char *)0x0;
  }
  return (char *)(piVar1[2] + 1 + piVar1[1]);
}

