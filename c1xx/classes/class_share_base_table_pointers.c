void __cdecl
class_share_base_table_pointers(c1_symbol *cls,c1_symbol *base,int base_offset,int unused)

{
  c1_u8 *pcVar1;
  byte bVar2;
  c1_class_record *pcVar3;
  byte bVar4;
  int iVar5;
  
  iVar5 = 0;
  do {
    pcVar3 = (cls->detail).cls;
    bVar2 = pcVar3->layout_flags3a;
    if (iVar5 == 0) {
      bVar4 = bVar2 >> 6 & 1;
    }
    else {
      bVar4 = bVar2 >> 7;
    }
    if (bVar4 == 0) {
      bVar4 = ((base->detail).cls)->layout_flags3a;
      if (iVar5 == 0) {
        bVar4 = bVar4 >> 6 & 1;
      }
      else {
        bVar4 = bVar4 >> 7;
      }
      if (bVar4 != 0) {
        if (iVar5 == 1) {
          pcVar3->vbptr_offset = ((base->detail).cls)->vbptr_offset + base_offset;
          pcVar1 = &((cls->detail).cls)->layout_flags3a;
          *pcVar1 = *pcVar1 | 0x80;
        }
        else {
          pcVar3->layout_flags3a = bVar2 | 0x40;
          if (iVar5 == 0) {
            ((cls->detail).cls)->vfptr_member = ((base->detail).cls)->vfptr_member;
          }
        }
      }
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  return;
}

