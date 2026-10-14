void __cdecl
decl_check_formal_parameter_type(c1_u8 flag_bit,c1_tag_symbol *tag,c1_declaration *decl)

{
  c1_specifier_words *spec;
  int iVar1;
  void *pvVar2;
  byte bVar3;
  c1_type *pcVar4;
  c1_symbol *pcVar5;
  uint uVar6;
  char *pcStack00000004;
  int ice_line;
  int inline_keyword;
  int warn_arg;
  
  if ((decl->context != 4) && (decl->context != 6)) {
    pcVar5 = decl->sym;
    if (pcVar5 == (c1_symbol *)0x0) {
      pcVar5 = sym_new_from_declarator(decl,3);
    }
    diag_error(0x4f,pcVar5,decl->type,tag);
    decl->type = g_type_int;
  }
  if (decl->type == (c1_type *)0x0) {
    decl->type = decl->sym->type;
  }
  if ((decl->flags2c & flag_bit) != 0) {
    (decl->spec).storage = (decl->spec).storage | 8;
  }
  iVar1 = decl->context;
  if ((iVar1 == 7) || (iVar1 == 8)) {
    if ((decl->declarator->flags30 & 2) == 0) {
      pvVar2 = decl->name;
      uVar6 = *(uint *)((int)pvVar2 + 8) & 0x40000000;
      if (((uVar6 == 0) || (pvVar2 != g_name_main)) && (pvVar2 != g_name_wmain)) {
        if ((((uVar6 != 0) && (pvVar2 == g_name_WinMain)) ||
            ((pvVar2 == g_name_DllMain || (pvVar2 == g_name_wWinMain)))) && (g_opt_Gz == 0)) {
          pcVar4 = type_with_qualifier_bits(decl->type,5);
          decl->type = pcVar4;
          pcVar5 = decl->sym;
          if (pcVar5 == (c1_symbol *)0x0) {
            pcVar5 = sym_new_from_declarator(decl,3);
          }
          warn_arg = 0x82;
LAB_10636770:
          diag_warning(3,7,pcVar5,warn_arg);
        }
      }
      else if (((g_opt_Gr != '\0') || (g_opt_Gc != '\0')) || (g_opt_Gz != 0)) {
        pcVar4 = type_with_qualifier_bits(decl->type,1);
        decl->type = pcVar4;
        pcVar5 = decl->sym;
        if (pcVar5 == (c1_symbol *)0x0) {
          pcVar5 = sym_new_from_declarator(decl,3);
        }
        warn_arg = 0x25;
        goto LAB_10636770;
      }
    }
    if (((decl->flags2c & 8) != 0) && (((decl->type->extra).params)->count == 0)) {
      pcVar4 = type_add_flags(decl->type,0x4000);
      decl->type = pcVar4;
    }
    switch((decl->spec).storage & 7) {
    case 0:
    case 2:
      bVar3 = (decl->spec).storage & 0xf9;
      (decl->spec).storage = bVar3 | 1;
      (decl->spec).storage = bVar3 | 0x21;
      break;
    case 3:
      if (((decl->spec).declspec & 0xc) != 0) {
        pcVar5 = decl->sym;
        if (pcVar5 == (c1_symbol *)0x0) {
          pcVar5 = sym_new_from_declarator(decl,3);
        }
        diag_error(0xc9,pcVar5);
        bVar3 = (decl->spec).storage & 0xf9;
        (decl->spec).storage = bVar3 | 1;
        (decl->spec).storage = bVar3 | 0x21;
      }
      if (g_block_depth != '\0') {
        decl_abstract_declarator_fragment_2(' ',decl);
        return;
      }
      break;
    case 4:
    case 5:
    case 6:
      pcVar5 = decl->sym;
      if (pcVar5 == (c1_symbol *)0x0) {
        pcVar5 = sym_new_from_declarator(decl,3);
      }
      diag_warning(1,0x2a,pcVar5);
      decl_abstract_declarator_fragment(decl);
      return;
    case 7:
      if ((decl->flags2c & 8) != 0) {
        decl_report_illegal_storage_class(decl);
        return;
      }
    }
    goto switchD_10606aa5_caseD_1;
  }
  bVar3 = (decl->spec).inlining;
  if ((bVar3 & 8) == 0) {
    if ((bVar3 & 1) != 0) {
      inline_keyword = 0xe;
      bVar3 = bVar3 & 0xfe;
      goto LAB_10636874;
    }
  }
  else {
    inline_keyword = 0xec;
    bVar3 = bVar3 & 0xf6;
LAB_10636874:
    (decl->spec).inlining = bVar3;
    if (iVar1 == 6) {
      diag_error(0x2df,inline_keyword);
    }
    else if (iVar1 == 4) {
      diag_error(0x2e0,inline_keyword);
    }
    else {
      pcVar5 = decl->sym;
      if (pcVar5 == (c1_symbol *)0x0) {
        pcVar5 = sym_new_from_declarator(decl,3);
      }
      diag_error(0x1b1,pcVar5,inline_keyword);
    }
  }
  iVar1 = decl->context;
  if (((iVar1 == 5) || (iVar1 == 6)) || (iVar1 == 0xb)) {
    spec = &decl->spec;
    bVar3 = (decl->spec).storage & 7;
    if (bVar3 != 5) {
      if (bVar3 != 0) {
        pcVar5 = decl->sym;
        if (pcVar5 == (c1_symbol *)0x0) {
          pcVar5 = sym_new_from_declarator(decl,3);
        }
        diag_warning(1,0x2a,pcVar5);
      }
      spec->storage = spec->storage & 0xfc | 4;
    }
    if (((((decl->spec).inlining & 7) == 0) && (bVar3 = (decl->spec).declspec, (bVar3 & 0x43) == 0))
       && ((bVar3 & 0xc) == 0)) {
      if (((decl->spec).allocate & 1) != 0) {
        decl_abstract_declarator_fragment_4(spec,decl);
        return;
      }
    }
    else {
      pcVar5 = decl->sym;
      if (pcVar5 == (c1_symbol *)0x0) {
        pcVar5 = sym_new_from_declarator(decl,3);
      }
      diag_warning(1,0x2a,pcVar5);
      bVar3 = spec->storage;
      spec->storage = '\0';
      spec->inlining = '\0';
      spec->declspec = '\0';
      spec->allocate = '\0';
      (decl->spec).segment = (void *)0x0;
      (decl->spec).flags8 = '\0';
      (decl->spec).pad09[0] = '\0';
      (decl->spec).pad09[1] = '\0';
      (decl->spec).pad09[2] = '\0';
      spec->storage = (spec->storage ^ bVar3 & 7) & 7 ^ spec->storage;
    }
  }
  else if (iVar1 == 3) {
    if ((g_compile_flags_c4 & 0x20000) == 0) {
      bVar3 = (decl->spec).storage & 7;
      if ((bVar3 < 4) || (6 < bVar3)) {
        if (bVar3 == 0) {
          if ((((decl->flags2c & 0x80) != 0) && ((decl->flags2d & 1) != 0)) &&
             ((decl->flags2c & 4) == 0)) {
            decl_abstract_declarator_fragment_3(decl);
            return;
          }
          if (((decl->spec).declspec & 8) == 0) {
            (decl->spec).storage = (decl->spec).storage & 0xfa | 2;
          }
          else {
            (decl->spec).storage = (decl->spec).storage & 0xf9 | 1;
          }
        }
      }
      else {
        pcVar5 = decl->sym;
        if (pcVar5 == (c1_symbol *)0x0) {
          pcVar5 = sym_new_from_declarator(decl,3);
        }
        diag_warning(1,0x2a,pcVar5);
        (decl->spec).storage = (decl->spec).storage & 0xfa | 2;
      }
    }
    else {
      bVar3 = (decl->spec).storage;
      if ((bVar3 & 7) == 0) {
        if ((g_compile_flags_c4 & 0x20) == 0) {
          if (((decl->spec).declspec & 8) == 0) {
            (decl->spec).storage = (decl->spec).storage & 0xfc | 4;
          }
          else {
            (decl->spec).storage = (decl->spec).storage & 0xf9 | 1;
          }
        }
        else {
          (decl->spec).storage = bVar3 & 0xfa | 2;
        }
      }
    }
  }
  if (((decl->spec).storage & 7) == 3) {
    if (((decl->spec).declspec & 0xc) != 0) {
      decl_check_export_linkage(decl);
      return;
    }
  }
  else if ((((decl->spec).declspec & 0xc) != 0) && ((g_compile_flags_c4 & 0x20000) != 0)) {
    decl_abstract_declarator_fragment_5(decl);
    return;
  }
switchD_10606aa5_caseD_1:
  if (decl->type != (c1_type *)0x0) {
    return;
  }
  pcStack00000004 = ".\\typesym.c";
  diag_fatal(1);
}

