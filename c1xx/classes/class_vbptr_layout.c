void __cdecl class_vbptr_layout(int cls,int *vbptr_offset,int *first)

{
  int iVar1;
  
  iVar1 = **(int **)(*(int *)(*(int *)(cls + 0x24) + 0x10) + 8);
  *vbptr_offset = *(int *)(*(int *)(cls + 0x24) + 0x30);
  if (first != (int *)0x0) {
    *first = *(int *)(*(int *)(iVar1 + 0x10) + 0x14);
  }
  return;
}

