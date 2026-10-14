void __fastcall decl_check_declarator_kind(c1_declaration *decl)

{
  int iVar1;
  byte bVar2;
  c1_type *pcVar3;
  
  bVar2 = (byte)decl->type->code;
  if ((bVar2 & 0x83) == 0x81) {
    iVar1 = decl->context;
    if (iVar1 == 3) {
      decl->context = 7;
      return;
    }
    if (0 < iVar1) {
      if (iVar1 < 3) {
        diag_error(0x20,decl->name,(g_struct_layouts[g_class_depth].tag)->type,
                   g_struct_layouts[g_class_depth].tag);
      }
      else if (iVar1 == 4) {
        diag_error(0x42);
        pcVar3 = type_pointer_to_function(decl->type);
        decl->type = pcVar3;
        return;
      }
    }
    pcVar3 = type_pointer_to_function(decl->type);
    decl->type = pcVar3;
    return;
  }
  if ((bVar2 & 0x8f) != 0x83) {
    return;
  }
  if ((decl->context == 5) || (decl->context == 6)) {
    if (decl->type->code == 0x4083) {
      diag_error(0x21c);
    }
    pcVar3 = type_intern_pointer_to(decl->type);
    decl->type = pcVar3;
  }
  else if (((decl->spec).storage & 7) != 7) {
    decl->flags2c = decl->flags2c | 0x80;
    if ((decl->type->code != 0x4083) && ((decl->type->extra).sym == (c1_symbol *)0x0)) {
      decl->flags2d = decl->flags2d | 1;
      return;
    }
  }
  return;
}

