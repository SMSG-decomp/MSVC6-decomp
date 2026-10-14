int __cdecl debug_type_record_array(c1_type *type,int element_index)

{
  ushort *puVar1;
  uint uVar2;
  int iVar3;
  
  puVar1 = g_cv_record_body;
  *g_cv_record_body = 0x1003;
  *(int *)(puVar1 + 1) = element_index;
  puVar1[3] = 0x11;
  puVar1[4] = 0;
  uVar2 = type_size(type);
  uVar2 = debug_cv_unsigned_numeric_leaf(puVar1 + 5,uVar2,0);
  *(undefined1 *)((uVar2 & 0xffff) + 10 + (int)puVar1) = 0;
  iVar3 = cvserver_emit_type(uVar2 + 0xb);
  return iVar3;
}

