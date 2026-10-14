uint __fastcall idb_release(c1xx_idb *idb)

{
  c1_u32 *pcVar1;
  c1_idb_browse_entry *pcVar2;
  c1_idb_region *pcVar3;
  c1_idb_include_state *states;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  if (idb->deps_stream == (c1xx_pdb_stream *)0x0) {
LAB_1048e394:
    uVar5 = 1;
  }
  else {
    iVar4 = (*idb->deps_stream->vtbl->release)();
    uVar5 = 0;
    if (iVar4 != 0) goto LAB_1048e394;
  }
  if (idb->deps_stream_backup == (c1xx_pdb_stream *)0x0) {
LAB_1048e3b1:
    uVar6 = 1;
  }
  else {
    iVar4 = (*idb->deps_stream_backup->vtbl->release)();
    uVar6 = 0;
    if (iVar4 != 0) goto LAB_1048e3b1;
  }
  if (idb->module_stream == (c1xx_pdb_stream *)0x0) {
LAB_1048e3cb:
    uVar7 = 1;
  }
  else {
    iVar4 = (*idb->module_stream->vtbl->release)();
    uVar7 = 0;
    if (iVar4 != 0) goto LAB_1048e3cb;
  }
  if (idb->module_stream_backup != (c1xx_pdb_stream *)0x0) {
    iVar4 = (*idb->module_stream_backup->vtbl->release)();
    uVar8 = 0;
    if (iVar4 == 0) goto LAB_1048e3ea;
  }
  uVar8 = 1;
LAB_1048e3ea:
  idb->module_stream_backup = (c1xx_pdb_stream *)0x0;
  idb->module_stream = (c1xx_pdb_stream *)0x0;
  idb->deps_stream_backup = (c1xx_pdb_stream *)0x0;
  idb->deps_stream = (c1xx_pdb_stream *)0x0;
  if (idb != (c1xx_idb *)0x0) {
    pdb_array_destroy(&(idb->file_times).deleted);
    pdb_array_destroy(&(idb->file_times).present);
    pcVar1 = (idb->file_times).range.data;
    if (pcVar1 != (c1_u32 *)0x0) {
      __3_YAXPAX_Z(pcVar1);
    }
    pcVar1 = (idb->file_times).domain.data;
    if (pcVar1 != (c1_u32 *)0x0) {
      __3_YAXPAX_Z(pcVar1);
    }
    pcVar1 = (idb->name_hash_bits).data;
    if (pcVar1 != (c1_u32 *)0x0) {
      __3_YAXPAX_Z(pcVar1);
    }
    pcVar2 = (idb->browse_lines).data;
    if (pcVar2 != (c1_idb_browse_entry *)0x0) {
      __3_YAXPAX_Z(pcVar2);
    }
    pcVar3 = (idb->file).regions.data;
    if (pcVar3 != (c1_idb_region *)0x0) {
      __3_YAXPAX_Z(pcVar3);
    }
    pdb_array_destroy(&(idb->header_signatures).deleted);
    pdb_array_destroy(&(idb->header_signatures).present);
    pcVar1 = (idb->header_signatures).range.data;
    if (pcVar1 != (c1_u32 *)0x0) {
      __3_YAXPAX_Z(pcVar1);
    }
    pcVar1 = (idb->header_signatures).domain.data;
    if (pcVar1 != (c1_u32 *)0x0) {
      __3_YAXPAX_Z(pcVar1);
    }
    pdb_array_destroy(&(idb->header_times).deleted);
    pdb_array_destroy(&(idb->header_times).present);
    pcVar1 = (idb->header_times).range.data;
    if (pcVar1 != (c1_u32 *)0x0) {
      __3_YAXPAX_Z(pcVar1);
    }
    pdb_array_destroy(&(idb->header_times).domain);
    pdb_array_destroy(&(idb->old_file_times).deleted);
    pdb_array_destroy(&(idb->old_file_times).present);
    pcVar1 = (idb->old_file_times).range.data;
    if (pcVar1 != (c1_u32 *)0x0) {
      __3_YAXPAX_Z(pcVar1);
    }
    pdb_array_destroy(&(idb->old_file_times).domain);
    states = (idb->include_stack).data;
    if (states != (c1_idb_include_state *)0x0) {
      pdb_ipm_elem48_vector_deleting_dtor(states,3);
    }
    __3_YAXPAX_Z(idb);
  }
  return uVar5 & uVar6 & uVar7 & uVar8;
}

