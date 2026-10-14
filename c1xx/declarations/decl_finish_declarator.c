void __fastcall decl_finish_declarator(c1_decl_record *rec)

{
  c1_sym_list *pcVar1;
  fe_name *pfVar2;
  bool bVar3;
  byte bVar4;
  ushort uVar5;
  c1_symbol *pcVar6;
  c1_type *pcVar7;
  c1_node *pcVar8;
  c1_type *pcVar9;
  int iVar10;
  short n;
  
  if ((rec->flags & 0x20) != 0) {
    decl_check_conversion_syntax(rec);
  }
  if (rec->chain_head == (c1_type *)0x0) {
    decl_warn_modifiers_on_data(rec);
    rec->flags = rec->flags | 4;
    rec->type = rec->spec_type;
    goto LAB_104015af;
  }
  decl_check_declarator_modifiers(rec);
  if ((rec->flags & 8) != 0) {
    pcVar6 = decl_member_function_class(rec);
    if ((pcVar6 == (c1_symbol *)0x0) || ((rec->spec[0] & 7) == 7)) {
      pcVar7 = (c1_type *)0x0;
      pcVar1 = rec->params->params;
      pcVar8 = decl_chain_default_arguments(rec->params->defaults);
      decl_set_parameter_type(rec->chain_head,(int)pcVar1,pcVar8,pcVar7);
    }
    else {
      pcVar7 = type_this_pointer(pcVar6,0x20,(ushort)rec->params->cv);
      pcVar1 = rec->params->params;
      pcVar8 = decl_chain_default_arguments(rec->params->defaults);
      decl_set_parameter_type(rec->chain_head,(int)pcVar1,pcVar8,pcVar7);
      *(byte *)&rec->chain_head->code = (byte)rec->chain_head->code | 0x85;
    }
    if ((short)rec->params->cv != 0) {
      bVar4 = (byte)rec->spec[0] & 7;
      if (bVar4 == 3) {
        pfVar2 = rec->name;
        if ((((pfVar2 == g_name_new) || (pfVar2 == g_name_delete)) || (pfVar2 == g_name_array_new))
           || (pfVar2 == g_name_array_delete)) {
          n = 0x10f;
        }
        else {
          n = 0x110;
        }
        diag_error(n,pfVar2);
        rec->flags = rec->flags | 1;
      }
      else if (pcVar6 == (c1_symbol *)0x0) {
        decl_finish_declarator_modifiers_fragment(bVar4,rec);
        return;
      }
    }
  }
  if ((((rec->flags & 0x10) != 0) && ((rec->spec_type->code & 0x200) != 0)) &&
     (bVar4 = (byte)rec->chain_tail->code, (bVar4 & 0x83) == 0x81)) {
    if (((bVar4 & 0x8f) == 0x85) && ((rec->spec[0] & 7) != 3)) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    pcVar6 = (rec->spec_type->extra).cls;
    if ((((pcVar6->detail).cls)->layout_flags3b & 0x80) != 0) {
      class_check_abstract_instantiation(pcVar6);
      rec->flags = rec->flags | 1;
    }
    if ((pcVar6->flags2 & 4) == 0) {
      if (bVar3) goto LAB_1040165a;
      uVar5 = (-(ushort)(g_linkage_stack[g_linkage_depth] != 2) & 0x4000) + 0x4000;
    }
    else if ((bVar3) || (iVar10 = class_member_may_be_declared(pcVar6), (char)iVar10 != '\0')) {
LAB_1040165a:
      if ((g_linkage_stack[g_linkage_depth] == 2) && (!bVar3)) {
        diag_warning(1,0xbe,rec->sym,pcVar6);
      }
      uVar5 = 0x8000;
    }
    else {
      uVar5 = 0x4000;
    }
    rec->chain_tail->code = rec->chain_tail->code | uVar5;
  }
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
  pcVar7 = rec->chain_head;
  pcVar9 = rec->chain_tail->base;
  if (pcVar7 != pcVar9) {
    pcVar9 = type_rebuild_chain(pcVar7->base,pcVar9);
    pcVar7->base = pcVar9;
    pcVar7 = type_intern(pcVar7);
  }
  rec->type = pcVar7;
LAB_104015af:
  if (rec->type == (c1_type *)0x0) {
    rec->flags = rec->flags | 1;
    rec->type = g_type_int;
  }
  return;
}

