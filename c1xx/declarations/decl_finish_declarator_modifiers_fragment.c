void __fastcall decl_finish_declarator_modifiers_fragment(byte storage_class,c1_decl_record *rec)

{
  c1_symbol *cls;
  fe_name *pfVar1;
  bool bVar2;
  byte bVar3;
  ushort uVar4;
  c1_type *pcVar5;
  c1_type *proto;
  int iVar6;
  short n;
  
  pfVar1 = rec->name;
  if ((((pfVar1 == g_name_new) || (pfVar1 == g_name_delete)) || (pfVar1 == g_name_array_new)) ||
     (pfVar1 == g_name_array_delete)) {
    n = 0x10f;
  }
  else if (storage_class == 3) {
    n = 0x110;
  }
  else {
    n = 0x10e;
  }
  diag_error(n,pfVar1);
  rec->flags = rec->flags | 1;
  if ((((rec->flags & 0x10) == 0) || ((rec->spec_type->code & 0x200) == 0)) ||
     (bVar3 = (byte)rec->chain_tail->code, (bVar3 & 0x83) != 0x81)) goto LAB_10401566;
  if (((bVar3 & 0x8f) == 0x85) && ((rec->spec[0] & 7) != 3)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  cls = (rec->spec_type->extra).cls;
  if ((((cls->detail).cls)->layout_flags3b & 0x80) != 0) {
    class_check_abstract_instantiation(cls);
    rec->flags = rec->flags | 1;
  }
  if ((cls->flags2 & 4) == 0) {
    if (bVar2) goto LAB_1040165a;
    uVar4 = (-(ushort)(g_linkage_stack[g_linkage_depth] != 2) & 0x4000) + 0x4000;
  }
  else if ((bVar2) || (iVar6 = class_member_may_be_declared(cls), (char)iVar6 != '\0')) {
LAB_1040165a:
    if ((g_linkage_stack[g_linkage_depth] == 2) && (!bVar2)) {
      diag_warning(1,0xbe,rec->sym,cls);
    }
    uVar4 = 0x8000;
  }
  else {
    uVar4 = 0x4000;
  }
  rec->chain_tail->code = rec->chain_tail->code | uVar4;
LAB_10401566:
  if ((rec->layer_flags & 2) != 0) {
    diag_error(0x21c);
    rec->flags = rec->flags | 1;
    rec->chain_head->code = rec->chain_head->code & 0xbfff;
    (rec->chain_head->extra).count = 1;
  }
  if ((rec->layer_flags & 1) != 0) {
    decl_assign_calling_conventions((int)rec);
  }
  decl_warn_modifiers_on_data(rec);
  proto = rec->chain_head;
  pcVar5 = rec->chain_tail->base;
  if (proto != pcVar5) {
    pcVar5 = type_rebuild_chain(proto->base,pcVar5);
    proto->base = pcVar5;
    proto = type_intern(proto);
  }
  rec->type = proto;
  if (rec->type == (c1_type *)0x0) {
    rec->flags = rec->flags | 1;
    rec->type = g_type_int;
  }
  return;
}

