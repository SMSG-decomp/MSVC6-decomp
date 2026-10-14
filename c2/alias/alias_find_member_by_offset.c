c2_symbol * __fastcall alias_find_member_by_offset(c2_symbol *cls,int off)

{
  c2_symbol *pcVar1;
  c2_symbol *pcVar2;
  
  for (pcVar1 = cls->storage;
      (pcVar2 = cls, pcVar1 != (c2_symbol *)0x0 && (pcVar2 = pcVar1, pcVar1->offset != off));
      pcVar1 = pcVar1->part_next) {
  }
  return pcVar2;
}

