void __cdecl class_init_virtual_base_members(c1_symbol *sym,char init_adjustor)

{
  c1_vbase_vector *bases;
  int iVar1;
  short index;
  
  index = 0;
  bases = ((sym->detail).cls)->vbases;
  while ((bases != (c1_vbase_vector *)0x0 && (iVar1 = (int)index, iVar1 < (int)(uint)bases->count)))
  {
    index = index + 1;
    if (bases->data[iVar1]->needs_vtordisp != '\0') {
      class_init_virtual_base_members_fragment(sym,bases->data[iVar1],bases,index,init_adjustor);
      return;
    }
  }
  return;
}

