uint __fastcall idb_release(c1_idb_state *idb)

{
  Stream *pSVar1;
  ulong *puVar2;
  fe_idb_browse_entry *pfVar3;
  fe_idb_region *pfVar4;
  fe_idb_include_state *elements;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  pSVar1 = idb->deps_stream;
  if (pSVar1 == (Stream *)0x0) {
LAB_10646a2b:
    uVar6 = 1;
  }
  else {
    iVar5 = (*pSVar1->vtbl->Release)(pSVar1);
    uVar6 = 0;
    if (iVar5 != 0) goto LAB_10646a2b;
  }
  pSVar1 = idb->deps_stream_2;
  if (pSVar1 == (Stream *)0x0) {
LAB_10646a48:
    uVar7 = 1;
  }
  else {
    iVar5 = (*pSVar1->vtbl->Release)(pSVar1);
    uVar7 = 0;
    if (iVar5 != 0) goto LAB_10646a48;
  }
  pSVar1 = idb->regions_stream;
  if (pSVar1 == (Stream *)0x0) {
LAB_10646a62:
    uVar8 = 1;
  }
  else {
    iVar5 = (*pSVar1->vtbl->Release)(pSVar1);
    uVar8 = 0;
    if (iVar5 != 0) goto LAB_10646a62;
  }
  pSVar1 = idb->regions_stream_2;
  if (pSVar1 != (Stream *)0x0) {
    iVar5 = (*pSVar1->vtbl->Release)(pSVar1);
    uVar9 = 0;
    if (iVar5 == 0) goto LAB_10646a81;
  }
  uVar9 = 1;
LAB_10646a81:
  idb->regions_stream_2 = (Stream *)0x0;
  idb->regions_stream = (Stream *)0x0;
  idb->deps_stream_2 = (Stream *)0x0;
  idb->deps_stream = (Stream *)0x0;
  if (idb != (c1_idb_state *)0x0) {
    pdb_array_destroy(&(idb->unit_files).isetDeleted.rgw);
    pdb_array_destroy(&(idb->unit_files).isetPresent.rgw);
    puVar2 = (idb->unit_files).rgr.rgt;
    if (puVar2 != (ulong *)0x0) {
      __3_YAXPAX_Z(puVar2);
    }
    puVar2 = (idb->unit_files).rgd.rgt;
    if (puVar2 != (ulong *)0x0) {
      __3_YAXPAX_Z(puVar2);
    }
    puVar2 = (idb->names).rgw.rgt;
    if (puVar2 != (ulong *)0x0) {
      __3_YAXPAX_Z(puVar2);
    }
    pfVar3 = (idb->browse_regions).data;
    if (pfVar3 != (fe_idb_browse_entry *)0x0) {
      __3_YAXPAX_Z(pfVar3);
    }
    pfVar4 = (idb->file).regions.data;
    if (pfVar4 != (fe_idb_region *)0x0) {
      __3_YAXPAX_Z(pfVar4);
    }
    pdb_array_destroy(&(idb->dependencies_2).isetDeleted.rgw);
    pdb_array_destroy(&(idb->dependencies_2).isetPresent.rgw);
    puVar2 = (idb->dependencies_2).rgr.rgt;
    if (puVar2 != (ulong *)0x0) {
      __3_YAXPAX_Z(puVar2);
    }
    puVar2 = (idb->dependencies_2).rgd.rgt;
    if (puVar2 != (ulong *)0x0) {
      __3_YAXPAX_Z(puVar2);
    }
    pdb_array_destroy(&(idb->dependencies).isetDeleted.rgw);
    pdb_array_destroy(&(idb->dependencies).isetPresent.rgw);
    puVar2 = (idb->dependencies).rgr.rgt;
    if (puVar2 != (ulong *)0x0) {
      __3_YAXPAX_Z(puVar2);
    }
    pdb_array_destroy(&(idb->dependencies).rgd);
    pdb_array_destroy(&(idb->file_times).isetDeleted.rgw);
    pdb_array_destroy(&(idb->file_times).isetPresent.rgw);
    puVar2 = (idb->file_times).rgr.rgt;
    if (puVar2 != (ulong *)0x0) {
      __3_YAXPAX_Z(puVar2);
    }
    pdb_array_destroy(&(idb->file_times).rgd);
    elements = (idb->include_stack).data;
    if (elements != (fe_idb_include_state *)0x0) {
      pdb_ipm_elem48_vector_deleting_dtor(elements,3);
    }
    __3_YAXPAX_Z(idb);
  }
  return uVar6 & uVar7 & uVar8 & uVar9;
}

