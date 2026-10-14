c1_symbol * __cdecl class_check_tag_kind_consistency(c1_symbol *sym,c1_u16 tag_code)

{
  c1_type *pcVar1;
  c1_type *pcVar2;
  ushort uVar3;
  c1_symbol *pcVar4;
  char cVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  if ((sym->kind & 0x1f) == 0x12) {
    if (sym->type == (c1_type *)0x0) {
      return (c1_symbol *)0x0;
    }
    sym = *(c1_symbol **)(*(int *)sym->type + 8);
    if (sym == (c1_symbol *)0x0) {
      pcVar4 = class_check_tag_kind_consistency_return_null();
      return pcVar4;
    }
  }
  if (((sym->flags2 & 0x10) == 0) && (sym = sym_hiding_partner(sym), sym == (c1_symbol *)0x0)) {
    return (c1_symbol *)0x0;
  }
  pcVar1 = sym->type;
  cVar5 = (char)pcVar1->code;
  pcVar2 = pcVar1;
  while (cVar5 < '\0') {
    pcVar2 = pcVar2->base;
    cVar5 = (char)pcVar2->code;
  }
  if (pcVar2->code != tag_code) {
    if ((tag_code & 0xfff) == 0x802) {
      return sym;
    }
    uVar3 = pcVar1->code & 0x20f;
    if (((uVar3 == 0x201) || (uVar3 == 0x202)) &&
       (((tag_code & 0x20f) == 0x201 || ((tag_code & 0x20f) == 0x202)))) {
      if (uVar3 == 0x201) {
        uVar7 = 0x1c;
        uVar6 = 0x1a;
      }
      else {
        uVar7 = 0x1a;
        uVar6 = 0x1c;
      }
      diag_warning(2,99,sym,uVar6,uVar7);
      sym->flags5 = sym->flags5 | 0x20;
      return sym;
    }
    diag_error(0xb,sym,pcVar1);
    sym->flags3 = sym->flags3 | 4;
  }
  class_check_member_pointer_representation(sym);
  return sym;
}

