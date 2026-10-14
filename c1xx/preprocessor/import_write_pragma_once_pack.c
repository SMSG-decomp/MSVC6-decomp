void __cdecl import_write_pragma_once_pack(void)

{
  if (g_import_implementation_only == 0) {
    fprintf((FILE *)g_import_tlh_file,"\n#pragma once\n#pragma pack(push, 8)\n");
    fprintf((FILE *)g_import_tlh_file,"\n#include <comdef.h>\n");
    if ((g_import_tlh_file->_flag & 0x20) != 0) {
      diag_fatal_file_errno(0x55,0x154,g_import_tlh_path);
    }
  }
  if (g_import_no_implementation == 0) {
    if (g_import_function_mapping == 0) {
      fprintf((FILE *)g_import_tli_file,"#pragma once\n");
    }
    if ((g_import_tli_file->_flag & 0x20) != 0) {
      diag_fatal_file_errno(0x55,0x154,g_import_tli_path);
    }
  }
  return;
}

