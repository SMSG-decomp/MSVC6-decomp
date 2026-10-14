void __fastcall decl_abstract_declarator(c1_declaration *decl)

{
  c1_specifier_words *spec;
  ushort uVar1;
  int iVar2;
  c1_tag_symbol *tag;
  void *pvVar3;
  byte bVar4;
  c1_type *pcVar5;
  c1_symbol *pcVar6;
  byte bVar7;
  uint uVar8;
  int kind_code;
  int warn_arg;
  
  if (((decl->context == 2) || (decl->context == 1)) &&
     (((bVar4 = (decl->spec).storage & 7, 3 < bVar4 && (bVar4 < 7)) ||
      ((((bVar4 == 3 || (bVar4 == 1)) || (bVar4 == 7)) || (((decl->spec).declspec & 0xc) != 0))))))
  {
    diag_error(0x47,decl->name);
    bVar4 = decl->flags2c;
    (decl->spec).storage = (decl->spec).storage | 8;
    decl->flags2c = bVar4 | 0x40;
  }
  if (decl->type == (c1_type *)0x0) {
    decl->type = decl->declarator->type;
    if ((decl->declarator->flags30 & 1) != 0) {
      decl->flags2c = decl->flags2c | 0x40;
    }
    decl_check_declarator_kind(decl);
    uVar1 = decl->type->code;
    bVar4 = (byte)uVar1;
    if ((-1 < (char)bVar4) && (bVar7 = (decl->spec).storage & 7, bVar7 != 7)) {
      if ((bVar4 >> 6 & 1) == 0) {
        if (((bVar7 != 1) && ((uVar1 & 0x200) != 0)) &&
           (tag = (decl->type->extra).tag, (tag->flags1 & 1) == 0)) {
          decl_check_formal_parameter_type('@',tag,decl);
          return;
        }
      }
      else if ((decl->context != 4) && (decl->context != 6)) {
        decl_check_void_variable('@',decl);
        return;
      }
    }
    if (decl->type == (c1_type *)0x0) {
      decl->type = decl->sym->type;
    }
  }
  if ((decl->flags2c & 0x40) != 0) {
    (decl->spec).storage = (decl->spec).storage | 8;
  }
  iVar2 = decl->context;
  if ((iVar2 == 7) || (iVar2 == 8)) {
    if ((decl->declarator->flags30 & 2) == 0) {
      pvVar3 = decl->name;
      uVar8 = *(uint *)((int)pvVar3 + 8) & 0x40000000;
      if (((uVar8 == 0) || (pvVar3 != g_name_main)) && (pvVar3 != g_name_wmain)) {
        if ((((uVar8 != 0) && (pvVar3 == g_name_WinMain)) ||
            ((pvVar3 == g_name_DllMain || (pvVar3 == g_name_wWinMain)))) && (g_opt_Gz == 0)) {
          pcVar5 = type_with_qualifier_bits(decl->type,5);
          decl->type = pcVar5;
          pcVar6 = decl->sym;
          if (pcVar6 == (c1_symbol *)0x0) {
            pcVar6 = sym_new_from_declarator(decl,3);
          }
          warn_arg = 0x82;
LAB_10636770:
          diag_warning(3,7,pcVar6,warn_arg);
        }
      }
      else if (((g_opt_Gr != '\0') || (g_opt_Gc != '\0')) || (g_opt_Gz != 0)) {
        pcVar5 = type_with_qualifier_bits(decl->type,1);
        decl->type = pcVar5;
        pcVar6 = decl->sym;
        if (pcVar6 == (c1_symbol *)0x0) {
          pcVar6 = sym_new_from_declarator(decl,3);
        }
        warn_arg = 0x25;
        goto LAB_10636770;
      }
    }
    if (((decl->flags2c & 8) != 0) && (((decl->type->extra).params)->count == 0)) {
      pcVar5 = type_add_flags(decl->type,0x4000);
      decl->type = pcVar5;
    }
    switch((decl->spec).storage & 7) {
    case 0:
    case 2:
      bVar4 = (decl->spec).storage & 0xf9;
      (decl->spec).storage = bVar4 | 1;
      (decl->spec).storage = bVar4 | 0x21;
      break;
    case 3:
      if (((decl->spec).declspec & 0xc) != 0) {
        pcVar6 = decl->sym;
        if (pcVar6 == (c1_symbol *)0x0) {
          pcVar6 = sym_new_from_declarator(decl,3);
        }
        diag_error(0xc9,pcVar6);
        bVar4 = (decl->spec).storage & 0xf9;
        (decl->spec).storage = bVar4 | 1;
        (decl->spec).storage = bVar4 | 0x21;
      }
      if (g_block_depth != '\0') {
        decl_abstract_declarator_fragment_2(' ',decl);
        return;
      }
      break;
    case 4:
    case 5:
    case 6:
      pcVar6 = decl->sym;
      if (pcVar6 == (c1_symbol *)0x0) {
        pcVar6 = sym_new_from_declarator(decl,3);
      }
      diag_warning(1,0x2a,pcVar6);
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
  bVar4 = (decl->spec).inlining;
  if ((bVar4 & 8) == 0) {
    if ((bVar4 & 1) != 0) {
      kind_code = 0xe;
      bVar4 = bVar4 & 0xfe;
      goto LAB_10636874;
    }
  }
  else {
    kind_code = 0xec;
    bVar4 = bVar4 & 0xf6;
LAB_10636874:
    (decl->spec).inlining = bVar4;
    if (iVar2 == 6) {
      diag_error(0x2df,kind_code);
    }
    else if (iVar2 == 4) {
      diag_error(0x2e0,kind_code);
    }
    else {
      pcVar6 = decl->sym;
      if (pcVar6 == (c1_symbol *)0x0) {
        pcVar6 = sym_new_from_declarator(decl,3);
      }
      diag_error(0x1b1,pcVar6,kind_code);
    }
  }
  iVar2 = decl->context;
  if (((iVar2 == 5) || (iVar2 == 6)) || (iVar2 == 0xb)) {
    spec = &decl->spec;
    bVar4 = (decl->spec).storage & 7;
    if (bVar4 != 5) {
      if (bVar4 != 0) {
        pcVar6 = decl->sym;
        if (pcVar6 == (c1_symbol *)0x0) {
          pcVar6 = sym_new_from_declarator(decl,3);
        }
        diag_warning(1,0x2a,pcVar6);
      }
      spec->storage = spec->storage & 0xfc | 4;
    }
    if (((((decl->spec).inlining & 7) == 0) && (bVar4 = (decl->spec).declspec, (bVar4 & 0x43) == 0))
       && ((bVar4 & 0xc) == 0)) {
      if (((decl->spec).allocate & 1) != 0) {
        decl_abstract_declarator_fragment_4(spec,decl);
        return;
      }
    }
    else {
      pcVar6 = decl->sym;
      if (pcVar6 == (c1_symbol *)0x0) {
        pcVar6 = sym_new_from_declarator(decl,3);
      }
      diag_warning(1,0x2a,pcVar6);
      bVar4 = spec->storage;
      spec->storage = '\0';
      spec->inlining = '\0';
      spec->declspec = '\0';
      spec->allocate = '\0';
      (decl->spec).segment = (void *)0x0;
      (decl->spec).flags8 = '\0';
      (decl->spec).pad09[0] = '\0';
      (decl->spec).pad09[1] = '\0';
      (decl->spec).pad09[2] = '\0';
      spec->storage = (spec->storage ^ bVar4 & 7) & 7 ^ spec->storage;
    }
  }
  else if (iVar2 == 3) {
    if ((g_compile_flags_c4 & 0x20000) == 0) {
      bVar4 = (decl->spec).storage & 7;
      if ((bVar4 < 4) || (6 < bVar4)) {
        if (bVar4 == 0) {
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
        pcVar6 = decl->sym;
        if (pcVar6 == (c1_symbol *)0x0) {
          pcVar6 = sym_new_from_declarator(decl,3);
        }
        diag_warning(1,0x2a,pcVar6);
        (decl->spec).storage = (decl->spec).storage & 0xfa | 2;
      }
    }
    else {
      bVar4 = (decl->spec).storage;
      if ((bVar4 & 7) == 0) {
        if ((g_compile_flags_c4 & 0x20) == 0) {
          if (((decl->spec).declspec & 8) == 0) {
            (decl->spec).storage = (decl->spec).storage & 0xfc | 4;
          }
          else {
            (decl->spec).storage = (decl->spec).storage & 0xf9 | 1;
          }
        }
        else {
          (decl->spec).storage = bVar4 & 0xfa | 2;
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
  diag_fatal(1,".\\typesym.c",0x5a3);
}

