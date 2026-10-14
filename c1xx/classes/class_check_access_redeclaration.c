c1_symbol * __fastcall
class_check_access_redeclaration(int class_depth,uint sym_flags2,c1_symbol *sym)

{
  c1_symbol *pcVar1;
  uint uVar2;
  byte bVar3;
  uint unaff_EBP;
  uint in_stack_00000010;
  uint in_stack_00000014;
  
  if (((g_class_def_stack[class_depth].flags ^ (byte)sym_flags2) & 3) != 0) {
    uVar2 = sym_flags2 & 3;
    if (uVar2 == 1) {
      in_stack_00000014 = 0x89;
    }
    else if (uVar2 == 2) {
      in_stack_00000014 = 0x8a;
    }
    else if (uVar2 == 3) {
      in_stack_00000014 = 0x8b;
    }
    bVar3 = g_class_def_stack[class_depth].flags & 3;
    if (bVar3 == 1) {
      in_stack_00000010 = 0x89;
    }
    else if (bVar3 == 2) {
      in_stack_00000010 = 0x8a;
    }
    else if (bVar3 == 3) {
      in_stack_00000010 = 0x8b;
    }
    diag_begin_global(g_token_position);
    if (g_ms_extensions == '\0') {
      diag_error(0x14b,sym,in_stack_00000010 & 0xff,in_stack_00000014 & 0xff);
    }
    else {
      diag_warning(3,0xf0,sym,in_stack_00000010 & 0xff,in_stack_00000014 & 0xff);
    }
    diag_end_global();
    sym->flags2 = (g_class_def_stack[g_class_depth].flags ^ sym->flags2) & 3 ^ sym->flags2;
  }
  pcVar1 = esu_check_tag_and_begin_enum(sym,unaff_EBP);
  return pcVar1;
}

