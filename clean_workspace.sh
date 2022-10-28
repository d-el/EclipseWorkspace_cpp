# Очистить директорию
RMF+=`find .metadata/.plugins/org.eclipse.cdt.core -type f -name "*"`
RMF+=" "
RMF+="find .metadata/.plugins/org.eclipse.debug.core/.launches"
RMF+=" "
RMF+=`find .metadata/.plugins/org.eclipse.core.resources -type f -name "*"`
RMF+=" "
RMF+=`find .metadata/.plugins/org.eclipse.ltk.core.refactoring -type f -name "*"`
RMF+=" "

# Удалить все кроме dialog_settings.xml
RMF+=`find .metadata/.plugins/org.eclipse.debug.ui -type f -name "*" -not -path "*dialog_settings.xml"`
RMF+=" "

# Удалить все кроме dialog_settings.xml
RMF+=`find .metadata/.plugins/org.eclipse.cdt.ui -type f -name "*" -not -path "*dialog_settings.xml"`
RMF+=" "

# удалить все *prj-*
RMF+=`find .metadata/.plugins/org.eclipse.core.runtime -type f -name "*prj-*"`
RMF+=" "

# Удалить директорию
RMF+=FreeRTOS_TAD_logs
RMF+=" "

echo ''
echo '[For removing]'
echo $RMF | tr -s ' ' '\n'
echo ''
echo [Removing]
rm -rf $RMF
echo ''
echo [Done]
