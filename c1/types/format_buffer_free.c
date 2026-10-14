void __cdecl format_buffer_free(int handle)

{
  int *piVar1;
  
  piVar1 = format_buffer_find(handle);
  *piVar1 = 0;
  return;
}

