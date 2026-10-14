char __cdecl mre_class_name_index(c1_symbol *cls)

{
  c1_pdb_namemap *pThis;
  c1xx_pdb_namemap_vtbl *pcVar1;
  c1_symbol *pcVar2;
  char *sz;
  int iVar3;
  c1_symbol **pni;
  
  pcVar2 = cls;
  pThis = g_pdb_gi->namemap;
  pni = &cls;
  pcVar1 = pThis->vtbl;
  sz = mre_qualified_name_text(&cls->kind);
  iVar3 = (*pcVar1->get_ni)(pThis,sz,(ulong *)pni);
  if (iVar3 == 0) {
    return '\0';
  }
  ((pcVar2->detail).cls)->gm_name_index = (c1_u32)cls;
  return '\x01';
}

