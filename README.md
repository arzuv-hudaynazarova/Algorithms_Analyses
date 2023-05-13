# Algoritma Analyses and Desing ks2

# Ödev_1'in açıklaması ve zaman karmaşıklığı:

 C dilinde yazılmış bir koddur. Kod, çeşitli işlemler yapmak için fonksiyonları kullanır. İşte kodun detaylı bir açıklaması ve fonksiyonlarının zaman karmaşıklığı:

main(): Bu, programın başladığı ana fonksiyondur. Bu fonksiyon, rastgele sayılar oluşturarak iki farklı dizi oluşturur, bunları sıralar, ortalamalarını alır ve en sonunda bir matris oluşturarak Floyd-Warshall algoritmasıyla en kısa yolunu bulur.

diziYazdir(): Bu fonksiyon, verilen bir diziyi ekrana yazdırır. Boyutu n olan bir dizi üzerinde tek bir döngü çalıştırdığı için bu fonksiyonun zaman karmaşıklığı O(n)'dir.

matrisYazdir(): Bu fonksiyon, verilen bir matrisi ekrana yazdırır. Boyutları n x n olan bir matris üzerinde iki iç içe döngü çalıştırdığı için bu fonksiyonun zaman karmaşıklığı O(n^2)'dir.

quickSort() ve partition(): Bu fonksiyonlar, QuickSort sıralama algoritmasını uygular. QuickSort, diziyi hızlı bir şekilde sıralar ve genellikle ortalama durumda O(n log n) zaman karmaşıklığına sahiptir. Ancak en kötü durumda zaman karmaşıklığı O(n^2)'ye kadar çıkabilir.

ortalamaBul(): Bu fonksiyon, verilen bir dizinin ortalamasını hesaplar. Boyutu n olan bir dizi üzerinde tek bir döngü çalıştırdığı için bu fonksiyonun zaman karmaşıklığı O(n)'dir.

matrisOlustur(): Bu fonksiyon, rastgele sayılardan oluşan bir matris oluşturur. Boyutları n x n olan bir matris üzerinde iki iç içe döngü çalıştırdığı için bu fonksiyonun zaman karmaşıklığı O(n^2)'dir.

floydWarshall(): Bu fonksiyon, Floyd-Warshall algoritmasını uygular. Floyd-Warshall, bir ağırlıklı graf üzerindeki tüm çiftlerin en kısa yolunu bulmak için kullanılan bir algoritmadır. Boyutları n x n olan bir matris üzerinde üç iç içe döngü çalıştırdığı için bu fonksiyonun zaman karmaşıklığı O(n^3)'dir.

yoluYazdir(): Bu fonksiyon, iki düğüm arasındaki en kısa yolun uzunluğunu yazdırır. Bu fonksiyon sabit zamanlı bir işlem yapar, bu yüzden zaman karmaşıklığı O(1)'dir.

Bu kod, çeşitli fonksiyonlar kullanarak bir dizi işlemler yürütür ve Floyd-Warshall algoritması gibi bazı karmaşık algoritmaları içerir. Tüm bu işlemlerin bir araya getirilmesi, genellikle işlemlerin birleştirilmiş zaman karmaşıklığını verir. Ancak, bu tür durumlarda genellikle en yüksek dereceli işlemi dikkate alırız, çünkü daha büyük giriş boyutlarına sahip olduğumuzda bu işlem genellikle toplam hesaplama süresini belirler.

Bu durumda, en yüksek dereceli işlem Floyd-Warshall algoritmasıdır. Bu algoritmanın zaman karmaşıklığı O(n^3)'dir. Bu, bu programın genel zaman karmaşıklığını O(n^3) yapar.

Bu, Floyd-Warshall algoritmasının herhangi bir graf üzerindeki tüm çiftlerin en kısa yolunu bulmak için kullanıldığında, algoritmanın her düğüm çifti için tüm diğer düğümleri kontrol etmesi gerektiği anlamına gelir. Bu, algoritmanın zaman karmaşıklığının O(n^3) olmasına neden olur.

Yani, bu kodun genel zaman karmaşıklığı O(n^3) olacaktır. Ancak, burada n'nin değeri 10 olduğu için, bu durumda kodun gerçek çalışma süresi genellikle çok hızlı olacaktır. Bu, n'nin sabit bir değer olduğu ve bu nedenle kodun çalışma süresinin genellikle de sabit olduğu anlamına gelir.

Not: Burada belirtilen zaman karmaşıklıkları, genellikle big-O gösterimi olarak adlandırılan bir gösterim kullanılarak ifade edilmiştir. Bu gösterim, bir algoritmanın performansının nasıl ölçüleceğini gösterirken genellikle kullanılır. Big-O gösterimi, en kötü durumda bir algoritmanın ne kadar süreceğine dair bir üst sınır sağlar. Ancak, bu her zaman gerçek dünya performansını tam olarak yansıtmayabilir, çünkü big-O gösterimi sabit faktörleri ve düşük dereceli terimleri görmezden gelir.


# Ödev_2 'nin açıklaması ve zaman karmaşıklığı:

 C programı, öncelikle belirlenen boyutta bir dizi oluşturur ve bu diziye rastgele sayılar atar. Ardından, dizi elemanlarını sıralar ve ortalamasını hesaplar. Ayrıca, belirli bir grafın en kısa yollarını bulur ve belirlenen bir eşik değerinin altındaki yolları yazar. İşlemlerin tamamlanmasının ne kadar sürdüğünü hesaplar ve yazdırır.

main fonksiyonu: Programın başladığı ve bittiği yerdir. Burada, dizi ve graf tanımlanır ve çeşitli işlemler gerçekleştirilir.

dizi_uret fonksiyonu: Belirtilen boyutta bir diziye rastgele sayılar atar.

sirala fonksiyonu: Dizi elemanlarını küçükten büyüğe doğru sıralar.

ortalama_bul fonksiyonu: Dizinin ortalama değerini hesaplar.

en_kisa_yollari_bul fonksiyonu: Floyd-Warshall algoritması kullanılarak belirli bir grafın en kısa yollarını bulur.

dizi_yazdir, graf_yazdir ve esik_alti_yollari_yazdir fonksiyonları: İsimlerinden de anlaşılacağı gibi, bu fonksiyonlar çeşitli çıktıları yazdırır.

Zaman karmaşıklığına gelince, en karmaşık işlem Floyd-Warshall algoritmasıdır. Bu algoritma, her bir düğüm çifti için tüm diğer düğümleri kontrol ettiği için zaman karmaşıklığı O(n^3)'dir. Burada n, grafın düğüm sayısıdır.

Diğer işlemler (dizi oluşturma, sıralama, ortalamanın hesaplanması vb.) genellikle daha az karmaşıktır. Dizi oluşturma ve ortalamanın hesaplanması O(n) karmaşıklığa sahiptir, burada n dizi boyutudur. Sıralama işlemi ise tipik olarak O(n^2) karmaşıklığa sahip bubble sort algoritması kullanılıyor.

Bu durumda, genel zaman karmaşıklığı, en karmaşık işlemin karmaşıklığı olan O(n^3) olacaktır.

