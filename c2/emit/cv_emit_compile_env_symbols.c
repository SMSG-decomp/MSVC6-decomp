void cv_emit_compile_env_symbols(void)

{
  uint32_t cb;
  char cVar1;
  int iVar2;
  uint32_t uVar3;
  uint8_t enc_flag;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint8_t *cursor;
  int iVar9;
  uint8_t *puVar10;
  uint8_t *puVar11;
  char *pcVar12;
  char *pcVar13;
  uint16_t reclen;
  uint16_t rectyp;
  uint8_t machine;
  uint8_t language;
  uint8_t compile_flags [2];
  uint8_t version_name [196];
  uint8_t *record;
  uint32_t record_length;
  char *enc_pdb;
  char *enc_cwd;
  uint pdb_len;
  int pdb_key_len;
  uint src_len;
  int src_key_len;
  char *enc_src;
  uint cmd_len;
  int cmd_key_len;
  char *enc_cmd;
  uint cl_len;
  int cl_key_len;
  char *enc_cl;
  uint cwd_len;
  
  g_cv_symbols_header_written = 1;
  cv_emit_symbols_signature();
  cv_emit_objname_record();
  if (g_opt_edit_and_continue != 0) {
    iVar9 = 0;
    cwd_len = 0;
    cl_key_len = 0;
    cl_len = 0;
    cmd_key_len = 0;
    cmd_len = 0;
    src_key_len = 0;
    src_len = 0;
    pdb_key_len = 0;
    pdb_len = 0;
    pcVar4 = getenv("enc_cwd");
    enc_cwd = pcVar4;
    enc_cl = getenv("enc_cl");
    enc_cmd = getenv("enc_cmd");
    enc_src = getenv("enc_src");
    enc_pdb = getenv("enc_pdb");
    if (g_opt_brepro == 0) {
      if (pcVar4 != (char *)0x0) {
        uVar6 = 0xffffffff;
        iVar9 = 4;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        cwd_len = ~uVar6;
      }
      if (enc_cl != (char *)0x0) {
        uVar6 = 0xffffffff;
        pcVar4 = enc_cl;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        cl_len = ~uVar6;
        cl_key_len = 3;
      }
      if (enc_cmd != (char *)0x0) {
        uVar6 = 0xffffffff;
        pcVar4 = enc_cmd;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        cmd_len = ~uVar6;
        cmd_key_len = 4;
      }
      if (enc_src != (char *)0x0) {
        uVar6 = 0xffffffff;
        pcVar4 = enc_src;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        src_len = ~uVar6;
        src_key_len = 4;
      }
      if (enc_pdb != (char *)0x0) {
        uVar6 = 0xffffffff;
        pdb_key_len = 4;
        pcVar4 = enc_pdb;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        pdb_len = ~uVar6;
      }
    }
    else {
      enc_cwd = (char *)0x0;
      enc_cl = (char *)0x0;
      enc_cmd = (char *)0x0;
      enc_src = (char *)0x0;
      enc_pdb = (char *)0x0;
    }
    uVar6 = 0xffffffff;
    pcVar4 = s_Microsoft__R__32_bit_C_C___Optim_107ab038;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    record_length =
         ~uVar6 + pdb_len + pdb_key_len + src_len + src_key_len + cmd_len + cmd_key_len + cl_len +
         cl_key_len + cwd_len + 0x18 + iVar9;
    iVar2 = -(record_length + 5 & 0xfffffffc);
    record = &stack0xffffffb0 + iVar2;
    *(short *)(&stack0xffffffb0 + iVar2) = (short)record_length;
    *(undefined2 *)(&stack0xffffffb2 + iVar2) = 0x1013;
    (&stack0xffffffb4)[iVar2] = (uint8_t)g_il_language;
    if ((g_opt_edit_and_continue == 0) && (g_opt_ZX == 0)) {
      enc_flag = '\0';
    }
    else {
      enc_flag = '\x01';
    }
    (&stack0xffffffb5)[iVar2] = enc_flag;
    (&stack0xffffffb6)[iVar2] = 0;
    (&stack0xffffffb7)[iVar2] = 0;
    *(undefined2 *)(&stack0xffffffb8 + iVar2) = (undefined2)g_opt_cpu_target;
    *(uint16_t *)(&stack0xffffffba + iVar2) = g_il_fe_version_major;
    *(uint16_t *)((int)&record + iVar2) = g_il_fe_version_minor;
    *(uint16_t *)((int)&record + iVar2 + 2) = g_il_fe_version_build;
    *(uint16_t *)((int)&record_length + iVar2) = g_p2_version_major;
    *(undefined2 *)((int)&record_length + iVar2 + 2) = 0;
    *(undefined2 *)((int)&enc_pdb + iVar2) = 0x1fe8;
    puVar10 = (uint8_t *)((int)&enc_pdb + iVar2 + 2);
    *(undefined4 *)(&stack0xffffffac + iVar2) = 0x1077deaa;
    iVar5 = cv_put_name(puVar10,s_Microsoft__R__32_bit_C_C___Optim_107ab038);
    pcVar4 = enc_cwd;
    cursor = puVar10 + iVar5;
    if (enc_cwd != (char *)0x0) {
      uVar7 = 0xffffffff;
      builtin_memcpy(puVar10 + iVar5,"cwd",4);
      uVar6 = cwd_len;
      do {
        pcVar12 = pcVar4;
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        pcVar12 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar12;
      } while (cVar1 != '\0');
      uVar7 = ~uVar7;
      puVar10 = (uint8_t *)(pcVar12 + -uVar7);
      puVar11 = cursor + iVar9;
      for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)puVar11 = *(undefined4 *)puVar10;
        puVar10 = puVar10 + 4;
        puVar11 = puVar11 + 4;
      }
      cursor = cursor + iVar9 + uVar6;
      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *puVar11 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar11 = puVar11 + 1;
      }
    }
    pcVar4 = enc_cl;
    if (enc_cl != (char *)0x0) {
      *(undefined2 *)*(char (*) [4])cursor = 0x6c63;
      pcVar12 = *(char (*) [4])cursor + cl_key_len;
      uVar6 = 0xffffffff;
      (*(char (*) [4])cursor)[2] = '\0';
      do {
        pcVar13 = pcVar4;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar13 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar13;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      pcVar4 = pcVar13 + -uVar6;
      pcVar13 = pcVar12;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar13 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar13 = pcVar13 + 4;
      }
      cursor = (uint8_t *)(pcVar12 + cl_len);
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar13 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar13 = pcVar13 + 1;
      }
    }
    pcVar4 = enc_cmd;
    iVar9 = cmd_key_len;
    if (enc_cmd != (char *)0x0) {
      *(char (*) [4])cursor = (char  [4])0x646d63;
      uVar6 = cmd_len;
      uVar7 = 0xffffffff;
      do {
        pcVar12 = pcVar4;
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        pcVar12 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar12;
      } while (cVar1 != '\0');
      uVar7 = ~uVar7;
      pcVar4 = pcVar12 + -uVar7;
      pcVar12 = *(char (*) [4])cursor + iVar9;
      for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pcVar12 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar12 = pcVar12 + 4;
      }
      cursor = (uint8_t *)(*(char (*) [4])cursor + iVar9 + uVar6);
      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pcVar12 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar12 = pcVar12 + 1;
      }
    }
    pcVar4 = enc_src;
    if (enc_src != (char *)0x0) {
      uVar7 = 0xffffffff;
      *(char (*) [4])cursor = (char  [4])0x637273;
      uVar6 = src_len;
      pcVar12 = *(char (*) [4])cursor + src_key_len;
      do {
        pcVar13 = pcVar4;
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        pcVar13 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar13;
      } while (cVar1 != '\0');
      uVar7 = ~uVar7;
      pcVar4 = pcVar13 + -uVar7;
      pcVar13 = pcVar12;
      for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pcVar13 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar13 = pcVar13 + 4;
      }
      cursor = (uint8_t *)(pcVar12 + uVar6);
      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pcVar13 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar13 = pcVar13 + 1;
      }
    }
    if (enc_pdb != (char *)0x0) {
      uVar7 = 0xffffffff;
      *(char (*) [4])cursor = (char  [4])0x626470;
      uVar6 = pdb_len;
      pcVar12 = *(char (*) [4])cursor + pdb_key_len;
      pcVar4 = enc_pdb;
      do {
        pcVar13 = pcVar4;
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        pcVar13 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar13;
      } while (cVar1 != '\0');
      uVar7 = ~uVar7;
      pcVar4 = pcVar13 + -uVar7;
      pcVar13 = pcVar12;
      for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pcVar13 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar13 = pcVar13 + 4;
      }
      cursor = (uint8_t *)(pcVar12 + uVar6);
      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pcVar13 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar13 = pcVar13 + 1;
      }
    }
    (*(char (*) [4])cursor)[0] = 0;
    (*(char (*) [4])cursor)[1] = '\0';
    *(undefined4 *)(&stack0xffffffac + iVar2) = 0x1077dfd4;
    (*g_hook_pad_section)(g_debug_symbols_section);
    uVar3 = record_length;
    puVar10 = record;
    cb = record_length + 2;
    *(undefined4 *)(&stack0xffffffac + iVar2) = 0x1077dfe3;
    (*g_writer_write_bytes_hook)(puVar10,cb);
    g_debug_symbols_section->offset = g_debug_symbols_section->offset + uVar3 + 2;
    return;
  }
  uVar6 = 0xffffffff;
  pcVar4 = "Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 12.00.8168.0";
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  rectyp = 1;
  uVar6 = ~uVar6;
  machine = (uint8_t)g_opt_cpu_target;
  reclen = (short)uVar6 + 6;
  language = (uint8_t)g_il_language;
  compile_flags[0] = '\0';
  compile_flags[1] = '\0';
  cv_put_name(version_name,"Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 12.00.8168.0");
  (*g_hook_pad_section)(g_debug_symbols_section);
  (*g_writer_write_bytes_hook)(&reclen,uVar6 + 8);
  g_debug_symbols_section->offset = g_debug_symbols_section->offset + uVar6 + 8;
  return;
}

