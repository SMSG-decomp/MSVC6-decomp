void __cdecl decl_check_operator_function(c1_symbol *sym,int at_definition)

{
  byte bVar1;
  ushort uVar2;
  c1_symbol *cls;
  c1_type *pcVar3;
  char cVar4;
  bool bVar5;
  char cVar6;
  c1_sym_list *pcVar7;
  byte bVar8;
  uint uVar9;
  int iVar10;
  c1_type *pcVar11;
  void *pvVar12;
  int nparams;
  c1_type **param_cursor;
  c1_type **param_cursor_2;
  c1_type **param_cursor_3;
  short n;
  int iVar13;
  int local_c;
  uint ndefaults;
  
  iVar13 = 0;
  bVar8 = sym->kind & 0x1f;
  ndefaults = 0;
  local_c = 0;
  bVar5 = false;
  if (((bVar8 != 7) && (bVar8 != 8)) && (bVar8 != 6)) {
    return;
  }
  bVar8 = sym->flags1;
  if ((bVar8 & 0x10) == 0x10) {
    return;
  }
  if ((bVar8 & 0x20) == 0x20) {
    return;
  }
  bVar1 = (sym->tail).fn.op_token;
  if (bVar1 == 1) {
    return;
  }
  if ((at_definition != 0) && ((bVar8 & 4) != 0)) {
    return;
  }
  uVar9 = (uint)bVar1;
  switch(uVar9) {
  case 0x34:
  case 0x41:
  case 0x53:
  case 0x76:
  case 0x8f:
    if ((bVar8 & 4) == 0) {
      diag_error(0x321,uVar9,0);
      sym->flags3 = sym->flags3 | 4;
      return;
    }
    if ((*(byte *)((int)&sym->tail + 8) & 1) == 0) {
      diag_error(0x321,uVar9,0x152);
      sym->flags3 = sym->flags3 | 4;
      return;
    }
  default:
    pcVar11 = sym->type;
    param_cursor = (c1_type **)
                   (*(int *)(*(int *)((-(uint)((pcVar11->code & 0x80) != 0) & (uint)pcVar11) + 8) +
                            0xc) + 8);
    nparams = iVar13;
    if (param_cursor != (c1_type **)0x0) {
      iVar13 = **(int **)(*(int *)((-(uint)((pcVar11->code & 0x80) != 0) & (uint)pcVar11) + 8) + 0xc
                         );
      ndefaults = (uint)*(byte *)(*(int *)(((uint)pcVar11 & -(uint)((pcVar11->code & 0x80) != 0)) +
                                          8) + 4);
      nparams = iVar13;
      if ((iVar13 == 1) && (((byte)(*param_cursor)->code >> 6 & 1) != 0)) {
        iVar13 = 0;
        nparams = iVar13;
      }
    }
    for (; (param_cursor != (c1_type **)0x0 && (iVar13 != 0)); iVar13 = iVar13 + -1) {
      pcVar11 = *param_cursor;
      if (pcVar11->code == 0x80d) {
        bVar5 = true;
      }
      else {
        iVar10 = type_is_class_or_enum(pcVar11);
        if ((((char)iVar10 == '\0') &&
            (iVar10 = type_is_template_type_parameter(pcVar11), (char)iVar10 == '\0')) &&
           ((pcVar11->code & 0xfff) != 0x802)) {
          bVar8 = (byte)pcVar11->code;
          if (((char)bVar8 < '\0') && ((bVar8 & 0x8f) == 0x80)) {
            pcVar11 = pcVar11->base;
            iVar10 = type_is_class_or_enum(pcVar11);
            if (((char)iVar10 != '\0') ||
               ((iVar10 = type_is_template_type_parameter(pcVar11), (char)iVar10 != '\0' ||
                ((pcVar11->code & 0xfff) == 0x802)))) goto LAB_1040500c;
          }
        }
        else {
LAB_1040500c:
          local_c = local_c + 1;
        }
      }
      param_cursor = param_cursor + 1;
    }
    iVar13 = *(int *)(*(int *)(((uint)sym->type & -(uint)((sym->type->code & 0x80) != 0)) + 8) + 0xc
                     );
    param_cursor_2 = (c1_type **)(iVar13 + 8);
    bVar8 = sym->flags1 & 4;
    if ((bVar8 != 0) && ((*(byte *)((int)&sym->tail + 8) & 1) != 0)) {
      local_c = local_c + 1;
      nparams = nparams + 1;
    }
    if (nparams == 0) {
      if (bVar8 == 0) {
        diag_error(0x329,(uint)(sym->tail).fn.op_token);
        sym->flags3 = sym->flags3 | 4;
        return;
      }
      if ((*(byte *)((int)&sym->tail + 8) & 1) != 0) {
        return;
      }
      diag_error(0x322,(uint)(sym->tail).fn.op_token);
      sym->flags3 = sym->flags3 | 4;
      return;
    }
    bVar8 = (sym->tail).fn.op_token;
    if (((bVar8 != 0x8c) && (bVar8 != 0x8d)) && (local_c == 0)) {
      diag_error(0x323,(uint)bVar8);
      sym->flags3 = sym->flags3 | 4;
    }
    if (((bVar5) && (bVar8 = (sym->tail).fn.op_token, bVar8 != 0x8c)) && (bVar8 != 0x76)) {
      diag_error(0x33d,(uint)bVar8);
      sym->flags3 = sym->flags3 | 4;
    }
    break;
  case 0x36:
  case 0x50:
  case 0x56:
  case 0x5e:
  case 0x81:
  case 0x92:
  case 0x95:
    diag_error(800,uVar9);
    sym->flags3 = sym->flags3 | 4;
    return;
  case 0x3d:
  case 0x54:
  case 0x55:
  case 0x5a:
  case 0x86:
    goto switchD_10404ef0_caseD_3d;
  }
  bVar8 = (sym->tail).fn.op_token;
  uVar9 = (uint)bVar8;
  switch(uVar9) {
  case 6:
    goto switchD_10404ef0_caseD_3d;
  case 0x31:
  case 0x46:
  case 0x4a:
  case 0x51:
    if (nparams != 1) goto switchD_10404ffa_caseD_32;
    if (bVar8 == 0x46) {
      (sym->tail).fn.op_token = 'Z';
    }
    else if (bVar8 == 0x4a) {
      (sym->tail).fn.op_token = '=';
    }
    else if (bVar8 == 0x51) {
      decl_check_operator_function_block_a(sym,1,ndefaults);
      return;
    }
    break;
  case 0x32:
  case 0x33:
  case 0x37:
  case 0x39:
  case 0x3a:
  case 0x3b:
  case 0x3e:
  case 0x3f:
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x45:
  case 0x47:
  case 0x48:
  case 0x49:
  case 0x4b:
  case 0x4c:
  case 0x4d:
  case 0x4e:
  case 0x4f:
  case 0x52:
  case 0x57:
  case 0x58:
  case 0x5b:
  case 0x5c:
  case 0x93:
switchD_10404ffa_caseD_32:
    if (2 < nparams) {
      n = 0x324;
      goto LAB_104789c4;
    }
    if (nparams != 2) {
      decl_check_operator_function_block_b(uVar9,sym,nparams,ndefaults);
      return;
    }
    break;
  case 0x34:
    if ((nparams < 3) || ((sym->flags3 & 1) != 0)) {
      if (1 < nparams) break;
      n = 0x325;
    }
    else {
      n = 0x324;
    }
    goto LAB_104789c4;
  case 0x38:
  case 0x40:
    if (nparams < 3) {
      if (nparams != 2) {
        (sym->tail).fn.op_token = (bVar8 != 0x38) + 'T';
        break;
      }
      if (((sym->flags1 & 4) == 0) || ((*(byte *)((int)&sym->tail + 8) & 1) == 0)) {
        param_cursor_2 = (c1_type **)(iVar13 + 0xc);
      }
      pcVar3 = *param_cursor_2;
      uVar2 = pcVar3->code;
      cVar4 = (char)uVar2;
      pcVar11 = pcVar3;
      cVar6 = cVar4;
      while (cVar6 < '\0') {
        pcVar11 = pcVar11->base;
        cVar6 = (char)pcVar11->code;
      }
      cVar6 = cVar4;
      if (((pcVar11->code & 0x10) != 0) || ((uVar2 & 0x800) != 0)) {
        while (cVar6 < '\0') {
          pcVar3 = pcVar3->base;
          cVar6 = (char)pcVar3->code;
        }
        if (((((pcVar3->code & 0x1f) == 0x13) || ((uVar2 & 0x800) != 0)) && (-1 < cVar4)) &&
           ((uVar2 & 0x2000) == 0)) break;
      }
      n = 0x327;
    }
    else {
      n = 0x326;
    }
LAB_104789c4:
    diag_error(n,uVar9);
    sym->flags3 = sym->flags3 | 4;
    break;
  case 0x3c:
  case 0x59:
  case 0x8f:
    goto switchD_10404ffa_caseD_3c;
  case 0x53:
    pcVar11 = sym->type->base;
    cls = g_scope_vector->entries[(short)sym->scope_index];
    bVar8 = (byte)pcVar11->code;
    if (((char)bVar8 < '\0') && ((bVar8 & 0x8f) == 0x80)) {
      pcVar11 = pcVar11->base;
    }
    uVar2 = pcVar11->code;
    if ((((char)uVar2 < '\0') || ((uVar2 & 0xfff) != 0x801)) && ((uVar2 & 0xfff) != 0x802)) {
      if ((uVar2 & 0x200) == 0) {
        if (((char)uVar2 < '\0') && (((uVar2 & 0x8f) == 0x86 || ((uVar2 & 0x8f) == 0x82)))) {
          uVar2 = pcVar11->base->code;
          if ((uVar2 & 0x300) == 0) {
            if ((char)uVar2 < '\0') {
              if ((uVar2 & 0xfff) != 0x802) goto LAB_10478aeb;
            }
            else if ((uVar2 & 0xfff) != 0x801) {
              decl_check_operator_function_arrow_fragment
                        (CONCAT22((short)((uint)pcVar11->base >> 0x10),uVar2),nparams,cls,pcVar11,
                         sym,nparams,ndefaults);
              return;
            }
          }
        }
        else {
LAB_10478aeb:
          diag_warning(2,0x11c,cls,pcVar11);
        }
      }
      else if (cls == (pcVar11->extra).cls) {
        diag_warning(2,0x11d,cls);
      }
    }
    goto switchD_10404ffa_caseD_3c;
  case 0x8c:
    pcVar11 = type_function_return(sym->type);
    if (((pcVar11->code & 0x8f) != 0x82) || (((byte)pcVar11->base->code >> 6 & 1) == 0)) {
      diag_error(0x338);
      sym->flags3 = sym->flags3 | 4;
    }
    pcVar11 = *param_cursor_2;
    cVar6 = (char)pcVar11->code;
    while (cVar6 < '\0') {
      pcVar11 = pcVar11->base;
      cVar6 = (char)pcVar11->code;
    }
    if (pcVar11->code != 0x2013) {
      decl_check_operator_new_fragment(sym,nparams,ndefaults);
      return;
    }
    break;
  case 0x8d:
    if (((byte)sym->type->base->code >> 6 & 1) == 0) {
      diag_error(0x331);
      sym->flags3 = sym->flags3 | 4;
    }
    pcVar11 = *param_cursor_2;
    if (((pcVar11->code & 0x8f) != 0x82) || (((byte)pcVar11->base->code >> 6 & 1) == 0)) {
      diag_error(0x32f,pcVar11);
      sym->flags3 = sym->flags3 | 4;
    }
    if (1 < nparams) {
      param_cursor_3 = (c1_type **)(iVar13 + 0xc);
      iVar13 = nparams;
      while (iVar13 = iVar13 + -1, iVar13 != 0) {
        if (((*param_cursor_3)->code & 0x200) != 0) {
          pvVar12 = symtab_1700_lookup(sym);
          pcVar7 = g_pending_parameter_scope;
          iVar13 = g_pending_function_word;
          g_pending_function_word = iVar13;
          g_pending_parameter_scope = pcVar7;
          if (pvVar12 == (void *)0x0) {
            class_declare_placement_delete_closure(sym);
            g_pending_function_word = iVar13;
            g_pending_parameter_scope = pcVar7;
          }
          break;
        }
        param_cursor_3 = param_cursor_3 + 1;
      }
    }
  }
switchD_10404ffa_caseD_7:
  uVar9 = (uint)(sym->tail).fn.op_token;
  if (uVar9 != 0x76) {
    if (uVar9 == 0x8c) {
      if ((int)(nparams - ndefaults) < 1) {
        diag_error(0x33e);
        sym->flags3 = sym->flags3 | 4;
      }
    }
    else if (ndefaults != 0) {
      diag_error(0x33f,uVar9);
      sym->flags3 = sym->flags3 | 4;
      return;
    }
  }
switchD_10404ef0_caseD_3d:
  return;
switchD_10404ffa_caseD_3c:
  if (1 < nparams) {
    decl_check_operator_params_tail(sym,nparams,ndefaults);
    return;
  }
  goto switchD_10404ffa_caseD_7;
}

