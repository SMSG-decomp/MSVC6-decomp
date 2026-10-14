byte __thiscall
pdb_open_validated(c1_pdb_session *session,char *pdb_name,c1_u32 *signature,c1_u32 *age,
                  long page_size,char *mode)

{
  char cVar1;
  int iVar2;
  c1_u32 cVar3;
  
  iVar2 = PDBExportValidateInterface(0x13092b6);
  if (iVar2 == 0) {
    diag_fatal_simple(0x386);
  }
  cVar1 = pdbmgr_open(session,pdb_name,&session->pdb,'\0',page_size,mode);
  if (cVar1 != '\0') {
    if (session->pdb == (c1xx_pdb *)0x0) {
      cVar3 = 0;
    }
    else {
      cVar3 = (*session->pdb->vtbl->query_signature)();
    }
    *signature = cVar3;
    if (session->pdb != (c1xx_pdb *)0x0) {
      cVar3 = (*session->pdb->vtbl->query_age)();
      *age = cVar3;
      return 1;
    }
    *age = 0;
    return 1;
  }
  return 0;
}

