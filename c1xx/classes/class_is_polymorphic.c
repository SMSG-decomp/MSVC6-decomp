c1_u8 __cdecl class_is_polymorphic(c1_symbol *cls)

{
  c1_class_record *pcVar1;
  c1_vbase_vector *pcVar2;
  c1_vtable_vector *pcVar3;
  int iVar4;
  short sVar5;
  
  if ((cls->flags2 & 4) != 0) {
    pcVar1 = (cls->detail).cls;
    if ((pcVar1->layout_flags3a & 0x40) != 0) {
      return '\x01';
    }
    pcVar3 = pcVar1->vftables;
    pcVar2 = pcVar1->vbases;
    sVar5 = 0;
    while( true ) {
      if ((pcVar3 != (c1_vtable_vector *)0x0) && (pcVar3->count != 0)) {
        return '\x01';
      }
      if ((pcVar2 == (c1_vbase_vector *)0x0) ||
         (iVar4 = (int)sVar5, (int)(uint)pcVar2->count <= iVar4)) break;
      sVar5 = sVar5 + 1;
      pcVar3 = pcVar2->data[iVar4]->vftables;
    }
  }
  return '\0';
}

