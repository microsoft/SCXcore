#Replicate output of JBoss AS 7
#/bin/sh
echo "========================================================================="
echo ""
echo "  JBoss Bootstrap Environment"
echo ""
echo "  JBOSS_HOME: $JBOSS_HOME"
echo ""
echo "  JAVA: $JAVA"
echo ""
echo "  JAVA_OPTS: $JAVA_OPTS"
echo ""
echo "========================================================================="
if [ "$2" = "-b" ]; then 
	echo ""
else 
	echo "JBoss Application Server 7.0.0.Final?"
fi
